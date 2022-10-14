#include <iostream>
#include<string>
#include"interface.hpp"
using namespace std;


int main(){
    printf("Notice:\n\t"
            "1. The maximum number of variables that can be entered is 100 in each calculation\n\t"
            "2. The name of variate only can be the combination of letters, other input is not accepted\n\t"
            "3. The value of variate only can be the specific value, can't support a formula\n\t"
            "4. When you state a variate, there can't be some spaces in the input\n\t"
            "5. Supported operations are only addition, subtraction and multiplication\n\t"
            "6. If you want to quit this procedure, you can input \"End\" or this procedure will not terminate\n");
    for(;;){
        string input[100]={};
        string variate[100]={};
        string value[100]={};
        int record_i = 0;
        int max_number = 100;
        bool flag_exist_variate = false;
        bool end_sign = false;

        for(int i=0;i<max_number;i++){
            cin>>input[i];
            if(input[i]=="End"){
                end_sign = true;
                break;
            }
            if(judge_equalSign_Exist(input[i])){
                if(judge_inputEqualSign_valid(input[i])==true){
                    flag_exist_variate = true;
                    split_vatiateAndValue(input,variate,value,record_i);
                    record_i++;
                }else{
                    printf("your input is invalid\n");
                    i=max_number;
                }
            }else if(flag_exist_variate == true){
                sort_variate(variate,value,record_i);
                string new_formula = replace_formula(input,variate,value,record_i,i);
                if(judge_inputFormula_valid(new_formula)){
                    new_formula = kill_all_parentheses(new_formula);
                    if(judge_is_formula(new_formula)==true){
                        printf("%s\n",calculate_additionAndmultiplication(new_formula).data());
                    }else{
                        printf("%s\n",new_formula.data());
                    }               
                }else{
                    printf("your input is invalid\n");
                }
                i=max_number;
            }else{
                if(judge_inputFormula_valid(input[i])){
                    string new_formula = kill_all_parentheses(input[i]);
                    if(judge_is_formula(new_formula)==true){
                        printf("%s\n",calculate_additionAndmultiplication(new_formula).data());
                    }else{
                        printf("%s\n",new_formula.data());
                    }
                }else{
                    printf("your input is invalid\n");
                }
                i=max_number;
            }
        }
        if(end_sign==true){
            break;
        }
    }
    return 0;
}
