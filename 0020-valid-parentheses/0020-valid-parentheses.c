bool isValid(char* s) {
    char nextToClose[10000] = "";
    int j = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '{'){
            nextToClose[j] = '}';
            j++;
        }
        else if(s[i] == '('){
            nextToClose[j] = ')'; 
            j++;
        }
        else if (s[i] == '['){
            nextToClose[j] = ']';
            j++;
        }else{
            if(j == 0){
                return 0;
            }
            if(s[i] == '}' && nextToClose[j-1] == '}'){
                j--;
                continue;
            }

            else if(s[i] == ']' && nextToClose[j-1] == ']'){
                j--;
                continue;
            }

            else if(s[i] == ')' && nextToClose[j-1] == ')'){
                j--;
                continue;
            }

            else{
                return 0;
            }
        }
    }
    if(j > 0){
        return 0;
    }

    return 1;
}