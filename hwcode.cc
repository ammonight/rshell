#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;


vector<string> parsing (char *line) {
  vector <char*> result;
  unsigned size = 0;
  
  //if a '#' is found, ignore rest of commmand
  //find size of char array
  for (; line[size] != '\0'; size++) {
    if (line[size] == '#') {
      line[size] = '\0';
      break;
    }
  }

//  cout << line << endl;

  //list of symbols to parse
  char semi[] = ";";
  char amp[] = "&&";
  char bars[] = "||";
  char sqrf[] = "[";
  char sqrr[] = "]";
  char parenf[] = "(";
  char parenr[] = ")";
  char test[] = "test";

  char command[256];
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

    if (line[i] == '[') {
      char* copy = new char[count+1];
      strcpy (copy, command);
      result.push_back(copy);
      result.push_back(sqrf);
      command[0] = '\0';
      count = 0;
      i++;
    }

    if (line[i] == ']') {
      char* copy = new char[count+1];
      strcpy (copy, command);
      result.push_back(copy);
      result.push_back(sqrr);
      command[0] = '\0';
      count = 0;
      i++;
    }

    if (line[i] == '(') {
      char* copy = new char[count+1];
      strcpy (copy, command);
      result.push_back(copy);
      result.push_back(parenf);
      command[0] = '\0';
      count = 0;
      i++;
    }
   
    if (line[i] == ')') {
      char* copy = new char[count+1];
      strcpy (copy, command);
      result.push_back(copy);
      result.push_back(parenr);
      command[0] = '\0';
      count = 0;
      i++;
    }

    if (line[i] == ' ' && line[i+1] == 't' && line[i+2] == 'e' &&
        line[i+3] == 's' && line[i+4] == 't' && line[i+5] == ' ') {
      char* copy = new char[count+1];
      strcpy (copy, command);
      result.push_back(copy);
      result.push_back(test);
      command[0] = '\0';
      count = 0;
      i+=5;
    }

    //seperates out 'test' if flanked by spaces or beginning of command
    
    if (i == 0 && line[i] == 't' && line[i+1] == 'e' &&
        line[i+2] == 's' && line[i+3] == 't' && line[i+4] == ' ') {
      char* copy = new char[count+1];
      strcpy (copy, command);
      result.push_back(copy);
      result.push_back(test);
      command[0] = '\0';
      count = 0;
      i+=4;
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



/*
void multiParse (char *line, char **argParams) {
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
      //delete[] copy;
    }
    
    if (line[i] == '&' && line[i+1] == '&') {
      char* copy = new char[count+1];
      strcpy (copy, command);
      result.push_back(copy);
      result.push_back(amp);
      command[0] = '\0';
      i+=2;
      count = 0;
      //delete[] copy;
    }
 
    if (line[i] == '|' && line[i+1] == '|') {
      char* copy = new char[count+1];
      strcpy (copy, command);
      result.push_back(command);
      result.push_back(bars);
      command[0] = '\0';
      i+=2;
      count = 0;
      //delete[] copy;
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
}
*/


void whitespace(char *lcmnds, char **argParams){
  while (*lcmnds != '\0') {
    while (*lcmnds == ' ' || *lcmnds == '\t' || *lcmnds == '\n')
      *lcmnds++ = '\0';
    *argParams++ = lcmnds;
    while (*lcmnds != '\0' && *lcmnds != ' ' &&
           *lcmnds != '\t' && *lcmnds != '\n')
      lcmnds++; 
  }
  *argParams = '\0';
}


//takes in separated vector of commands and executes them
int execForkVp( char **argParams) {

  pid_t c_pid;
  int status;
  
  c_pid = fork();

  if( c_pid < 0){ 
    perror("fork failed");
    exit(1);
  }

  else if( c_pid == 0 ){  //MOST IMPORTANT PART OF FNCTN

    printf("Child: executing command\n");
    if (execvp( *argParams, argParams) < 0) {
      return 3; //This means that execvp failed
    }
  }

  else {
    while (wait (&status) != c_pid);
  }

  //ENDS HERE
/*
  else if( c_pid > 0 ){

    if( ( pid = wait(&status)) < 0){
      perror("wait");
      exit(1);
    }
    
    printf("Parent: finished.\n");
  }

*/
  return 1;

}

int main(){

  char wholeLine[2000];
  vector<string> commandList;

  //unsigned i = 0;

  while(1){
  
    cout << "$";
    cin.getline(wholeLine, 2000);
    //char* cstr = new char;
    //strcpy (cstr, wholeLine.c_str());
    //vector<string> result = parsing(cstr);
    //for (unsigned i = 0; i < result.size(); i++){
    //  cout << result.at(i) << endl;
    //}

    /*if( result.at(i) != ";" || result.at(i) != "&&" ||
        result.at(i) != "||"){
      char *csttr = new char[result.at(i).length() + 1];
      strcpy (csttr, result.at(i).c_str());
      temp = csttr;
      cout << temp[0] << endl;
      delete [] csttr;
    }*/
    commandList = parsing(wholeLine); 
    for (unsigned i = 0; i < commandList.size(); i++) {
      char *argParams[100]; 
      char *cstr = new char[commandList.at(i).size() + 1];
      strcpy (cstr, commandList.at(i).c_str());
      whitespace (cstr, argParams);

      //code to determine what to do with line
      if (strcmp (argParams[0], "exit") == 0) {
        exit(0);
      }
      
      execForkVp (argParams);
    }

    //for( int i = 0; i <= DiffAP.size(); i++){
   // if ( strcmp( argParams[0], "exit" ) == 0 )
     // exit(0);
   // execForkVp( argParams );
    //}

  }

  return 0;
}
