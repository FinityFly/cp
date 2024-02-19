#include <iostream>
#include <vector>

using namespace std;

string timeConversion(string s) {
    string output;
    vector<string> tokens;
    char schar[s.length()];
    for (int i = 0; i < sizeof(schar); i++) { 
        schar[i] = s[i]; 
    }
    char *token = strtok(schar, ":"); 
    while (token != NULL) { 
        tokens.push_back(token);
        token = strtok(NULL, ":"); 
    } 
    string shour = tokens[0];
    string indicator = tokens[2];
    indicator = indicator.substr(2, 2);
    int ihour = stoi(shour);
    if(indicator=="PM"){
        if(ihour != 12){
            ihour += 12;
            shour = to_string(ihour);
            output = shour + ":" + tokens[1] + ":" + tokens[2].substr(0, 2);
            return output;
        }else{
            return s.substr(0, 8);
        }
    }else{
        if(ihour!=12){
            return s.substr(0, 8);
        }else{
            output = "00:" + tokens[1] + ":" + tokens[2].substr(0, 2);
            return output;
        }
    }
}

int main()
{
    string s = "06:40:03AM";
    string result = timeConversion(s);
    cout << "\n";
    cout << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
