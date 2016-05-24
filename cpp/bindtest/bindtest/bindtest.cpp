// bindtest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "bindtest.h"
#include <iostream>


#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>

#pragma comment( lib, "odbc32.lib" )

int _tmain(int argc, _TCHAR* argv[])
{
	initTestODBC();
	return 0;
}

void initTestODBC()
{
  SQLCHAR       SqlState[6], Msg[SQL_MAX_MESSAGE_LENGTH];
  SQLINTEGER    NativeError;
  SQLSMALLINT   MsgLen = SQL_MAX_MESSAGE_LENGTH;
  SQLRETURN     retcode;
  
  int rc=0;

  // 1.  Create a handle for the environment.
  SQLHANDLE hEnv ;
 
  rc = SQLAllocHandle( SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv ) ;
  if (rc != SQL_SUCCESS)
  {
    FatalAppExitA( 0,"ERROR: Allocate environment handle");
  }
   

  // 2.  Next, set the version of ODBC to use to ODBC version 3.
  rc = SQLSetEnvAttr( hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0 ) ; 
  if (rc != SQL_SUCCESS)
  {
    FatalAppExitA( 0,"ERROR: setting the environment attribute setting to ODBC version 3");
  }

  // 3.  Allocate the connection handle.  
  SQLHANDLE hConn ;

  rc = SQLAllocHandle( SQL_HANDLE_DBC, hEnv, &hConn );
  if (rc != SQL_SUCCESS)
  {
    FatalAppExitA( 0,"ERROR: allocate handle");
  }

  // 4. Set attributes for connection
  rc = SQLSetConnectAttrA( hConn, SQL_ODBC_CURSORS, (void *)SQL_CUR_USE_DRIVER, SQL_IS_INTEGER  );
  rc = SQLSetConnectAttrA( hConn, SQL_ATTR_AUTOCOMMIT, (void *)SQL_AUTOCOMMIT_ON, SQL_IS_INTEGER  );

  char currentDir[250];
  char *getUser = new char[256];
  char *getPwd = new char[256];
  char *getDataSource = new char[256];
  GetCurrentDirectoryA(250,currentDir);
  strcat(currentDir,"\\bindtest.ini");
  GetPrivateProfileStringA("DB_SETTINGS", "DATASOURCE", 0, getDataSource, 50, currentDir);
  GetPrivateProfileStringA("DB_SETTINGS", "USER", 0, getUser, 50, currentDir);
  GetPrivateProfileStringA("DB_SETTINGS", "PASSWORD", 0, getPwd, 50, currentDir);

  // Set ODBS datasource name for connection
  SQLCHAR* dsnName = (SQLCHAR*)getDataSource; 
  // Set user and password for informix12
  SQLCHAR* userid = (SQLCHAR*) getUser;  // User
  SQLCHAR* password = (SQLCHAR*)getPwd;  // Password

  // 5.  Open database connection.
  rc = SQLConnectA(hConn,dsnName, SQL_NTS, userid, SQL_NTS, password,SQL_NTS) ;
  if (rc != SQL_SUCCESS)
  {
    FatalAppExitA( 0,"ERROR: SQLConnectA");
  }

  // SDK Client version
  SQLCHAR odbcver[10];
  SQLSMALLINT odbcver_len;
  SQLGetInfoA(hConn, SQL_DRIVER_VER,&odbcver,10,&odbcver_len);

  // 6.  Create and allocate a statement
  SQLHANDLE hStmt ;
  rc = SQLAllocHandle( SQL_HANDLE_STMT, hConn, &hStmt );
  if (rc != SQL_SUCCESS)
  {
    FatalAppExitA( 0,"ERROR: allocate handle for statement");
  }

  long cbValue = SQL_NTS;
  // 7. Bind Parameters with values "2.5" and "1.3"
  rc = SQLBindParameter(hStmt,1,SQL_PARAM_INPUT,SQL_C_CHAR, SQL_DECIMAL, 4,0,"2.5",0, &cbValue);
  rc = SQLBindParameter(hStmt,2,SQL_PARAM_INPUT,SQL_C_CHAR, SQL_DECIMAL, 4,0,"1.3",0, &cbValue);

  // It Works!!!!
  //rc = SQLBindParameter(hStmt,1,SQL_PARAM_INPUT,SQL_C_CHAR, SQL_DOUBLE, 4,0,"2.5",0, &cbValue);
  //rc = SQLBindParameter(hStmt,2,SQL_PARAM_INPUT,SQL_C_CHAR, SQL_DOUBLE, 4,0,"1.3",0, &cbValue);

  // 8.  Form a query to run 
  SQLCHAR* query = (SQLCHAR*)"{call sp_test_proc_case_1(?,?)}" ;

  // 9. Execute Statement
  rc = SQLExecDirectA(hStmt,(unsigned char *)query,SQL_NTS);
  if (rc != SQL_SUCCESS)
  {
	// initialize retcode
	retcode = 100;
	char sError[255];
	// Get Error
	if(retcode)
	{
	  retcode = SQLGetDiagRecA(SQL_HANDLE_STMT,hStmt,1,SqlState,&NativeError,Msg,sizeof(Msg),&MsgLen);
	}
	if(retcode)
	{
	  retcode = SQLGetDiagRecA(SQL_HANDLE_DBC,hConn,1,SqlState,&NativeError,Msg,sizeof(Msg),&MsgLen);
	}
	if(retcode)
	{
	  retcode = SQLGetDiagRecA(SQL_HANDLE_ENV,hEnv,1,SqlState,&NativeError,Msg,sizeof(Msg),&MsgLen);
	}
	printf( "ERROR SQLExecDirect has FAILED!! ERROR: %s \n", Msg);
	sprintf(sError,"ERROR SQLExecDirect has FAILED!! Driver=%s SqlState=%s NativeError=%d Msg=%s",odbcver,SqlState,NativeError,Msg);
	FatalAppExitA( 0, sError) ;
  }
  else
  {
	FatalAppExitA( 0, "SUCCESS!!!!!!!") ;  
  }

  // free up resources.
  SQLFreeHandle( SQL_HANDLE_STMT, hStmt ) ;
  SQLFreeHandle( SQL_HANDLE_DBC, hConn ) ;
  SQLFreeHandle( SQL_HANDLE_ENV, hEnv ) ;
}
