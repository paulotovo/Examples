#include <string>
 
using namespace std;

string& LTrim(string &str) 
{
  size_t i = 0;
  while(i < str.size() && isspace(str[i]))  
    ++i; 
  return str.erase(0, i);
}

string& RTrim(string &str) 
{
  size_t i = str.size();
  while(i > 0 && isspace(str[i - 1])) 
    --i;
  return str.erase(i, str.size());
}

string& Trim(string &str) 
{
  return LTrim(RTrim(str));
}

int main()
{
  string s1("  abc");
  string s2("abc  ");
  string s3(" abc   ");

  LTrim(s1);
  RTrim(s2);
  Trim(s3);

  return 0;
}