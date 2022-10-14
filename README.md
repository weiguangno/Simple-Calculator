# Simple-Calculator
This is a kind of simple calculator without graphical interface

CS205 C/C++ Programming -Project 2
Name: 付治文
SID: 12112709
Part 1 – Analysis
	首先，此次project中所要实现的所有功能，列于下面：
1. 对输入的数据进行读取和相关的处理
2. 整体框架的搭建
3. 实现对变量的判断和处理
4. 实现将表达式之中所有的变量变成它们对应的数值
5. 实现对输入的表达式是否正确进行判断，并给予相应的反馈
6. 实现对不同运算符的优先级的关系的处理
7. 加减乘三个运算符的基本实现（无限精度）
8. 函数在输入的表达式中的实现（sqrt( )函数可以调整任意精度）
9. 处理所有包含括号的情况
	其次，分析每一个要实现功能所需做的工作：
	以下所有的实现都是用字符串的形式进行操作与处理
	对输入的数据进行读取和相关的处理（已实现）
	通过cin将用户输入的值以字符串的形式传递给一个字符串数组input[ ]中
	当要判断和处理其中的数据时，直接调用input[ ]即可
	整体框架的搭建（已实现）
	 
	实现对变量的判断和处理
	判断输入的数据中是否包含有‘=’来进行判断输入的是否为变量声明
	然后将‘=’前后的部分拆开进行valid的判断
	前面的部分只支持a~z和A~Z之间的字母的排列组合，但不允许变量名称中包含函数的名称
	后面的部分只支持一个具体的数值，可以是负数，浮点数和科学计数法形式的浮点数
	对于valid的输入，把前后部分分开来进行存储，前面的部分存入variate[ ]，后面的部分存入value[ ]
	实现将表达式之中所有的变量变成它们对应的数值
	在表达式中，找出所有和变量名称相同的部分字符串，并将表达式中的变量名擦除，然后在相应位置上插入它对应的数值字符串
	实现对输入的表达式是否正确进行判断，并给予相应的反馈
	对表达式中的括号、负号、小数点、科学计数法中的e和数学函数这五个方面都进行存在性和正确性的判断
	在检验存在性的时候，只需将字符串中的每一个字符取出和对应想检验的字符进行对比，如果相等就存在
	在检验正确性的时候，需要判断每个符号前后所有可能出现的字符的所有可能，并处理相关的特殊情况
	如果检验存在性或者正确性的时候，出现问题，则进行报错反馈
	实现对不同运算符的优先级的关系的处理
	对字符串进行拆分，但是拆分的方式是以‘+’、‘-’、‘*’为边界将字符串表达式拆成运算符的位置部分和数值部分，并且将他们分别存储到split_position[ ]和split_data[ ]之中
	然后，进行乘法的运算，先将‘*’的个数记录下来，然后找出字符串中‘*’所在位置的前后的数值，并将它们进行乘法操作（进行乘法之前要进行判断输入的数据是什么类型的），将结果存放在前一个被操作数的split_data[ ]的位置中，然后将后面所有的数据向前移动一位，再将split_position[ ]中已经运算过的‘*’对应的数据擦除，然后后面的数据向前移动一位，并将原本记录先来的‘*’的个数减一，然后重复上述步骤，直到最开始记录的‘*’的个数减为0为止
	之后再进行加法和减法操作，类似于乘法，只是将其中判断的是‘*’改成‘+’or‘-’就可以了
	最终只需要输出split_data[0]的值，即为运算之后得到的值
	加减乘三个运算符的基本实现（无限精度）
	加法和减法（对于整数）
	用计算机底层的加法运算方式去操作数值字符串，从而完成相应的加法运算，对于减法而言，只是正数和负数的加法，因此只需要在加法运算中多判断一下符号位就可以了
	乘法（对于整数）
	同样是借鉴计算机底层的乘法运算的方式，通过乘数的每一位和被乘数相乘，然后把所有的数移位之后相加即可
	加法、减法和乘法（对于浮点数）
	本质上是将浮点数的小数点的位置记下来，然后擦除小数点，使浮点数变成整数，然后在利用整数的加减法和乘法运算算出结果之后将小数点再添加进去（主要要考虑的就是小数点的位置的变化）
	函数在输入的表达式中的实现（sqrt( )函数可以调整任意精度）
	对于abs( )函数：
	只需要判断得到的数的首项是不是为‘-’即可，是则擦除，否则不做改动
	对于sqrt( )函数：
	本质是使用二分法无限逼近所要求的值，先设定一个上界和下界，然后将它们平方之后的数比较要开根的数是否包含要开根的数，没有的话，就对上下界进行移动（我是上下界都成2或都除以2），当落在中间的时候，我把上下界的中间值的平方和要开根的数进行比较，如果小了就将下界乘2，大了就将上界除2，结束条件就是误差中间值的平方和要开根的数的差小于我们要求的数即可
	处理所有包含括号的情况 
	先找出最内层的一对括号，然后将括号内的数据进行处理，括号中的内容可能是一个负数，也可能是一个函数的括号，也可能是一个较短的表达式，区分这三者只需要判断一下就行，而找出最内层的方法，只需要用一个变量不断去记录左括号的位置，直到出现第一个右括号，那么记录到的左右括号的位置就是最内层的括号位置
	找到最内层括号后将其中的数据进行处理，并将包括括号在内的参与操作的位都擦除，然后将处理后的数据插入至相应的位置

Part 2 – Code
	每一个功能对应的代码
	对输入的数据进行读取和相关的处理
	string input[100]={};
	cin>>input[i];
	整体框架的搭建
	int main(){
	    for(;;){
	        string input[100]={};
	        string variate[100]={};
	        string value[100]={};
	        int record_i = 0;
	        int max_number = 100;
	        bool flag_exist_variate = false;
	        bool end_sign = false;
	
	        for(int i=0;i<max_number;i++){
	            cin>>input[i];
	            if(input[i]=="End"){
	                end_sign = true;
	                break;
	            }
	            if(judge_equalSign_Exist(input[i])){
	                if(judge_inputEqualSign_valid(input[i])==true){
	                    flag_exist_variate = true;
	                    split_vatiateAndValue(input,variate,value,record_i);
	                    record_i++;
	                }else{
	                    printf("your input equalSign is invalid\n");
	                    i=max_number;
	                }
	            }else if(flag_exist_variate == true){
	                sort_variate(variate,value,record_i);
	                string new_formula = replace_formula(input,variate,value,record_i,i);
	                if(judge_inputFormula_valid(new_formula)){
	                    new_formula = kill_all_parentheses(new_formula);
	                    if(judge_is_formula(new_formula)==true){
	                        printf("%s\n",calculate_additionAndmultiplication(new_formula).data());
	                    }else{
	                        printf("%s\n",new_formula.data());
	                    }               
	                }else{
	                    printf("your input newFormula is invalid\n");
	                }
	                i=max_number;
	            }else{
	                if(judge_inputFormula_valid(input[i])){
	                    string new_formula = kill_all_parentheses(input[i]);
	                    if(judge_is_formula(new_formula)==true){
	                        printf("%s\n",calculate_additionAndmultiplication(new_formula).data());
	                    }else{
	                        printf("%s\n",new_formula.data());
	                    }
	                }else{
	                    printf("your input Formula is invalid\n");
	                }
	                i=max_number;
	            }
	        }
	        if(end_sign==true){
	            break;
	        }
	    }
	    return 0;
	}

	实现对变量的判断和处理
	//judge_variate.cpp
	bool judge_equalSign_Exist(string a);
	bool judge_equalSign_Right(string a);
	bool judge_inputEqualSign_valid(string a);
	实现将表达式之中所有的变量变成它们对应的数值
	void split_vatiateAndValue(string* formula,string* variate,string* value,int index);
	string replace_formula(string* input,string* variate,string* value,int record_i,int i);
	void sort_variate(string* variate,string* value,int record_i);
	实现对输入的表达式是否正确进行判断，并给予相应的反馈
	//judge_formula.cpp
	bool judge_parentheses_Exist(string a);
	bool judge_parenthesesPairs_Right(string a);
	bool judge_negativeSign_Exist(string a);
	bool judge_negativeSign_Right(string a);
	bool judge_point_Exist(string a);
	bool judge_point_Right(string a);
	bool judge_e_Exist(string a);
	bool judge_e_Right(string a);
	bool judge_function_Exist(string a);
	bool judge_function_Right(string a);
	bool judge_inputFormula_valid(string a);
	bool judge_is_formula(string a);
	实现对不同运算符的优先级的关系的处理
	string calculate_additionAndmultiplication(string a);
	加减乘三个运算符的基本实现（无限精度）
	//basicOpreation.cpp
	string change_form_tofloat(string a);
	int compare(string str1,string str2);
	string ADD_INT(string str1,string str2);
	string SUB_INT(string str1,string str2);
	string MUL_INT(string str1,string str2);
	int count_numbersAfterPoint(string a);
	string earse_point(string a);
	string insert_point_mul(string a,int number);
	string add_zerAfterPoint(string a,int difference);
	string ADD_FLOAT(string a,string b);
	string SUB_FLOAT(string a,string b);
	string MUL_FlOAT(string a,string b);
	函数在输入的表达式中的实现（sqrt( )函数可以调整任意精度）
	//Math.Method
	string sqrt(string str);
	string abs(string a);
	int compare_leftToright_value(string str1,string str2);
	string cut_half(string a);
	处理所有包含括号的情况
	string kill_all_parentheses(string a);
	代码可以从以下两个途径获得：
	Github对应的网址：https://github.com/weiguangno/Simple-Calculator
	压缩包中的文件

Part 3 – Result & Verification
	Test case #1:
	Input：2+3
	Output：5
	Input：5+2*3
	Output：11
 
	Test case #2:
	Input：（5+2）*3
	Output：21
 
	Test case #3:
	Input：
	x=3
	y=6
	x+2*y
	Output：15
 
	Test case #4:
	Input：sqrt(3.0)
	Output：1.7320508075688772935940540863286596362513591884635388851165
 
	Test case #5:
	Input：99999999999999999.2222222+1.0
	Output：100000000000000000.2222222
 

