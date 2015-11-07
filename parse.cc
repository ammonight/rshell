//parsing function
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

vector<string> parsing (char *line) {
  vector <char*> result;
  unsigned size = 0;
  for (; line[size] != '\0'; size++) {
    if (line[size] == '#') {
      line[size] = '\0';
      break;
    }
  }

//  cout << line << endl;

  char semi[] = ";";
  char amp[] = "&&";
  char bars[] = "||";
  char command[size + 1];
  unsigned count = 0;
  for (unsigned i = 0; line[i] != '\0'; i++) {
    if (line[i] == ';') {
//      cout << command << " ;" << endl;
//      char copy[count] = command;
      char* copy = new char[count+1];
      strcpy (copy, command);
      result.push_back(copy);
      result.push_back(semi);
      command[0] = '\0';
      count = 0;
      i++;
    }
    
    if (line[i] == '&' && line[i+1] == '&') {
      char* copy = new char[count+1];
      strcpy (copy, command);
      result.push_back(copy);
      result.push_back(amp);
      command[0] = '\0';
      i+=2;
      count = 0;
    }
 
    if (line[i] == '|' && line[i+1] == '|') {
      char* copy = new char[count+1];
      strcpy (copy, command);
      result.push_back(command);
      result.push_back(bars);
      command[0] = '\0';
      i+=2;
      count = 0;
    }

    command[count] = line[i];
    command[count+1] = '\0';
    count++;
  }
  result.push_back(command);

  vector<string> strings;
  string str;
  for (unsigned i = 0; i < result.size(); i++) {
//    cout << result.at(i) << endl;
    str = result.at(i);
    strings.push_back(str);
  }

  return strings;
}

int main() {
  string str = "";
  cout << "enter a command" << endl;
  getline (cin, str);
  //char cstr[str.length() + 1] = str.c_str();
  char* cstr = new char[str.length()+1];
  strcpy (cstr, str.c_str());
  for (int i = 0; cstr[i] != 0; i++) {
    cout << cstr[i];
  }
  cout << endl;
  vector<string> data = parsing(cstr);
//  cout << data.size() << endl << endl;
  for (unsigned i = 0; i < data.size(); i++) {
    cout << data.at(i) << endl;
  }
  delete[] cstr;
  return 0;
}


