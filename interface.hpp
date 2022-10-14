#include<iostream>
#include<string>
using namespace std;

//judge_formula.cpp
bool judge_parentheses_Exist(string a);
bool judge_parenthesesPairs_Right(string a);
bool judge_negativeSign_Exist(string a);
bool judge_negativeSign_Right(string a);
bool judge_point_Exist(string a);
bool judge_point_Right(string a);
bool judge_e_Exist(string a);
bool judge_e_Right(string a);
bool judge_function_Exist(string a);
bool judge_function_Right(string a);
bool judge_inputFormula_valid(string a);
bool judge_is_formula(string a);

//judge_variate.cpp
bool judge_equalSign_Exist(string a);
bool judge_equalSign_Right(string a);
bool judge_inputEqualSign_valid(string a);

//function.cpp
void split_vatiateAndValue(string* formula,string* variate,string* value,int index);
string replace_formula(string* input,string* variate,string* value,int record_i,int i);
void sort_variate(string* variate,string* value,int record_i);
string calculate_additionAndmultiplication(string a);
string kill_all_parentheses(string a);

//basicOpreation.cpp
string change_form_tofloat(string a);
int compare(string str1,string str2);
string ADD_INT(string str1,string str2);
string SUB_INT(string str1,string str2);
string MUL_INT(string str1,string str2);
int count_numbersAfterPoint(string a);
string earse_point(string a);
string insert_point_mul(string a,int number);
string add_zerAfterPoint(string a,int difference);
string ADD_FLOAT(string a,string b);
string SUB_FLOAT(string a,string b);
string MUL_FlOAT(string a,string b);
int compare_leftToright_value(string str1,string str2);
string cut_half(string a);

//Math.Method
string sqrt(string str);
string abs(string a);
