







# <p align=center> Quine–McCluskey Algorithm </p>
### <p align=center> Youssef Elmahdy & Hussein Heggi
### <p align=center> Instructor: Mohamed Shalaan
### <p align=center> The American Univesity in Cairo 






 
## Introduction
<font size = "10">
Using the Quine-McCluskey technique, Boolean functions can be minimized. Early in the 1950s, Willard V. Quine and Edward J. McCluskey separately developed it. The algorithm is a useful instrument for designing digital circuits because it offers a methodical and effective way to simplify Boolean expressions with numerous variables. Mathematical expressions known as boolean functions work on one or more binary inputs to create a binary output. They frequently function as part of the digital logic circuits that conduct AND, OR, and NOT logical operations. The representation of boolean functions can take many forms, such as truth tables, logic gates, and algebraic formulas. The Petrick's method is a way that the Quine-McCluskey algorithm employs to find the minimum sum of products (MSP) form of a Boolean function. A canonical version of the Boolean function with the fewest terms and variables is the MSP form. It is helpful for reducing the number of logic gates and simplifying the design of digital circuits. The Boolean function is first represented by the Quine-McCluskey method in a tabular format known as the prime implicant chart. All potential minterms and the prime implicants that encompass them are listed in the prime implicant chart. A product term that covers at least one minimum that no other product word does is said to be a prime implicant. The algorithm then employs a series of stages to streamline the prime implicant chart and pinpoint the prime implicants that are absolutely necessary for covering all of the Boolean function's minimum terms. The essential prime implicants are used to construct the MSP form of the Boolean function. For reducing Boolean functions, the Quine-McCluskey algorithm offers a strong and effective approach. It is extensively used in the construction of digital circuits as well as other branches of computer science and engineering where boolean operations are significant. </font>
 
## Program design
 <font size = "10">
This is a C++ program that implements the Quine-McCluskey algorithm for Boolean functions. The program is divided into several functions that are called by the main function. The main function takes two arguments: a Boolean function in the form of sum-of-products (SoP) and the number of variables in the Boolean function. The program then performs several operations on the input function to reduce it to its simplest form.
The first function called is Get_Fun(), which takes the input function and removes any white spaces. It then parses the input function by splitting it into individual terms separated by + and stores these terms in a vector. (Hussein)
 
The second function called is Validate_Fun(), which validates the input function to make sure that it is in the correct form. The function checks that each term in the function has no more than n variables and that the variables are in non-decreasing order. The function also checks that each variable is one of the first n variables in the Boolean function. (Hussein)
 
The following function is called Gen_Fun(), which generates all possible combinations of the input function. It does this by iteratively adding one variable at a time to each term in the input function until all terms contain all n variables. This generates all possible combinations of the input function. (Hussein)
 
The preceding function called is Convert(), which converts the minterms of the Boolean function into binary form. The function takes each minterm in the input function and converts it into binary form, where each variable is represented by a 0 or a 1. The binary representation is stored in a vector. (Hussein)
 
Next, a function called TruthTable(), which generates the truth table for the Boolean function. The function takes the binary representation of each minterm generated in the previous function and calculates the output of the Boolean function for each possible combination of inputs. The function then prints the truth table. (Youssef)
 
Then, the function called is RConvert(), which converts the binary representation of the minterms back to decimal form. The function takes each binary representation and converts it back to its decimal equivalent. The decimal equivalent is stored in a vector. (Hussein)
 
The next function called is SoP_PoS(), which generates the sum-of-products and product-of-sums representations of the Boolean function. The function uses the decimal representation of the minterms generated in the previous function to generate the sum-of-products and product-of-sums representations of the Boolean function. The function then prints these representations. (Hussein)
 
The next function called is ImplicationTable(), which generates the implication table for the Boolean function. The implication table is used to find the prime implicants of the Boolean function. (Youssef)
 
The oneCount() function takes a string as an input and returns the number of 1s in the string. This function is used to determine the number of 1s in each binary representation of the minterms in the boolean expression. The minterms are then sorted based on the number of 1s using the std::sort() function, which is used in the ImplicationTable() function to arrange the minterms in a specific order. (Youssef)
The CompareBits() function takes two strings as inputs and returns true if the two strings differ by only one bit. This function is used to compare two binary representations of minterms and check if they differ by only one bit. If two binary representations of minterms differ by only one bit, then they can be combined to form a prime implicant. (Youssef)
 
The ReplaceBits() function takes two strings as inputs and returns a new string that contains '-' at the position where the two strings differ. This function is used to create a new binary representation for the prime implicant that is formed by combining two minterms. The '-' symbol is used to represent the bit that differs between the two minterms. (Youssef)
 
The next function called is Prime_Implicants(), which finds the prime implicants of the Boolean function. The function uses the implication table generated in the previous function to find the prime implicants. (Hussein & Youssef)
 
The restorePIs function takes a string s as input and restores the minterms from it. The function first determines the number of variables numVars from the length of the input string. It then uses a loop to generate all possible combinations of 0s and 1s for numVars variables using bit shifting. For each combination, it checks if the combination matches the input string s by comparing each bit in the combination with the corresponding character in the input string. If a combination matches the input string, the corresponding minterm is added to a vector minterms. Finally, the function loops through the vector minterms. (Youssef)

The final function called is Essential_PI(), which finds the essential prime implicants of the Boolean function. The function uses the prime implicants found in the previous function to find the essential prime implicants. The function then prints the essential prime implicants. (Hussein)

The main program includes two functions: Examples and Operation, calling and utilizing above functions.
The Examples function initializes an array of strings with 10 different boolean expressions and an array of integers with the number of literals in each expression. The function then prompts the user to select one of the 10 options by printing them on the screen using cout statements. After selecting an option, the function sets the input string reference to the corresponding expression and the input integer reference to the corresponding number of literals. (Youssef)
 
The Operation function first prompts the user to select an option from the menu which is also printed on the screen. The menu options include choosing an existing example, inserting a new example, and exiting the program. The function uses a do-while loop to repeatedly prompt the user to select an option until the user chooses to exit. (Hussein)

If the user selects option 1, the function calls the Examples function to prompt the user to select an existing expression, and then passes the selected expression and the number of literals to the QM function. The QM function then minimizes the expression and prints the minimized expression on the screen.
If the user selects option 2, the function prompts the user to enter the number of literals in their expression and then to enter the expression itself. The function then passes the entered expression and the number of literals to the QM function. The QM function minimizes the expression and prints the minimized expression on the screen.
If the user selects option 3, the function prints a message on the screen thanking the user for using the program and then terminates the program using the exit() function.
In both cases, after the QM function has minimized the expression, the program prompts the user to try again or exit. If the user chooses to exit, the program terminates. Otherwise, the program returns to the menu to prompt the user to select another option.
Overall, this program implements the Quine-McCluskey algorithm to reduce a Boolean function to its simplest form. The program takes a Boolean function in the form of sum-of-products and the number of variables in the Boolean function as input, and generates the truth table, sum-of-products, product-of-sums, implication table, prime implicants, and essential prime implicants of the Boolean function. </font>
 
## Problem Reporting
 <font size = "10">
-The main issue with the program is its complexity. It takes up a large space in the memory due to the large number of nested loops in the program and the maximum number of variables the program can handle ,which is ten variables. This can lead to huge truth tables which is very costly in terms of memory and time

-The naming convention of variables is not consistent throughout the code, which can lead to confusion. This is due to the fact that two people wrote the code so Inconsistency was bound to happen and also due to the lack of time that we can’t change them. 

-The code does not handle exceptions, which can cause the program to terminate abruptly. This is also due to the lack of time to enhance the program.

-There may exist code redundancy, where the same code is executed multiple times for different inputs. This is due to the fact that two people wrote the code.

-There is no destructor in the code, which can lead to memory leaks if the object of the class is dynamically allocated.

-Another problem with the program is that it can't handle the expression if it isnot in alphabetical order. To clarify, a problem can handle "ac + b" but can't handle "ca + b".
 </font>

## Program Build
 <font size = "10">
After the user opens the Git-Hub repo he will download both the .h and .cpp QM files in addition to the main. The user then runs it in a c++ compiler. The program is user friendly, when you run the program you have two options either to perform a Quine-McCluskey operation or to exit the program if you press the first option a new menu appears with three options the first of which is to choose one of the ten hard-coded examples to perform the operation on. We tried to make each example as unique as possible to further test our program, but if the user isn’t satisfied there’s always the option to input your example with the desired number of variables but in a correct SoP form and in an alphabetical order starting from the first literal as shown in the problems’ section. A remark to ensure the most experience from the program when manually entering your example please end your example with a “$” sign . In this menu there also exists an exit option just like the previous menu. After you choose your desired option the program prints the truth table of the function with both SoP and PoS in their canonical form. Moreover, the program displays the prime implicants of the function with the minterms that each prime implicant covers in addition to the essential prime implicants showing which minterms are covered by them and which are not. The program then asks the user either to make another operation in the same way simply by pressing any key except “e”. By pressing “e”, this will take the user back to the previous menu to choose a new way to test the program or to simply exit. The program will always keep running unless you exit from the main menu. </font>   
 
## Conclusion
 <font size = "10">
The Quine-McCluskey algorithm is an effective instrument for minimizing boolean functions. This algorithm is particularly helpful for condensing big boolean expressions that would take a long time and effort to do so manually. In order to create expressions that are logically equivalent to the original expressions, the algorithm first compares groups of binary numbers to find common patterns. It then combines these patterns. The Quine-McCluskey algorithm's guarantee of locating the smallest sum-of-products expression is one of its primary benefits. This means that, in terms of the number of terms and the number of literals, the algorithm's output will always be the simplest and most effective representation of the original boolean statement. Scalability is another benefit of the Quine-McCluskey method. It is appropriate for use in complicated digital circuit design and other boolean algebraic applications because it can handle boolean expressions with a lot of variables and terms. The Quine-McCluskey method has some drawbacks despite its benefits. One drawback is that, particularly for expressions with a lot of variables, it can be computationally costly. This can be reduced by utilizing cutting-edge software and hardware optimization methods, but it is still difficult. Another drawback is that the algorithm does not account for the physical restrictions and limitations of the hardware that will be used to execute the boolean expression. Because of this, even though the minimized expression may be ideal in terms of its logical structure, it might not be the most effective or economical application from a hardware standpoint. The Quine-McCluskey algorithm is a useful instrument for reducing the complexity of boolean expressions, but it should be used in conjunction with other design factors and optimization strategies. It can help simplify digital circuits and boost their performance, but it's essential to take into account the constraints and trade-offs that come with actually putting this algorithm to use. Engineers and designers can choose when and how to use the Quine-McCluskey algorithm in their creations by being aware of its advantages and disadvantages. </font>


