/*
	   Syed Muhammad Hassan
	   i230519
	   Section G

*/
#pragma once
#include<iostream>
using namespace std;

// DON'T CHANGE THE PROTOTYPES OF FUNCTION 

//----------------------- Q1 -----------------------

char* BaseConverter(float number, int base)
{

	
	float temp_decimal_neg = number;

	if (number < 0)
	{
		number = number * (-1);

	}
	int number_int = number;
	int decimal_num_int = number;
	float decimal_num_float = number;
	float float_answer;
	int index_decimal = 0;

	if (number_int != number)
	{
		float_answer = decimal_num_float - decimal_num_int;

		while (float_answer > 0)
		{
			float_answer = float_answer * base;
			int int_answer = float_answer;
			float_answer = float_answer - int_answer;
			index_decimal++;

		}

	}
	float fl_answer;
	int in_answer;
	int index = 0;
	float temp = number;
	float temp_1 = number;
	if (temp_1 == 0)
	{
		index = 1;
	}
	while (temp_1 > 0)
	{
		fl_answer = temp_1 / base;
		in_answer = temp_1 / base;
		temp_1 = in_answer;
		index++;

	}

	//2s complement 
	if (temp_decimal_neg < 0)
	{
		temp = pow(base, index) - number;
		float_answer = ((pow(base, index) - pow(base, -(index_decimal))) - number) + 1;
		decimal_num_float = float_answer;
		decimal_num_int = float_answer;


	}
	else
	{
		float_answer = 0, decimal_num_float = number, decimal_num_int = number;
	}

	//for decimal point
	char* decimal_answer = new char[index + index_decimal + 2];

	char* answer = new char[index + 1];
	for (int i = 0; i < index; i++)
	{
		answer[i] = '0';
	}
	for (int i = 0; i < index + index_decimal + 1; i++)
	{
		decimal_answer[i] = '0';
	}


	fl_answer = 0, in_answer = 0;
	int index_loop = index - 1;
	while (temp > 0)
	{


		fl_answer = temp / base;

		in_answer = temp / base;

		float dec_answer = ((fl_answer - in_answer)) * base;


		int value = 48 + dec_answer;
		if (value > 57)
		{
			value = (value - 58) + 65;
		}
		char value_1 = value;
		answer[index_loop] = value_1;
		temp = in_answer;
		index_loop--;

	}

	answer[index] = '\0';

	for (int i = 0; i < index + 1; i++)
	{
		if (i != index)
			decimal_answer[i] = answer[i];
		else
			decimal_answer[i] = '.';

	}

	int decimal_index_loop = index + 1;

	if (number_int != number)
	{
		float_answer = decimal_num_float - decimal_num_int;

		while (float_answer > 0)
		{
			float_answer = float_answer * base;
			int int_answer_1 = float_answer;
			int int_answer = float_answer;
			int_answer = 48 + int_answer;
			if (int_answer > 57)
			{
				int_answer = 65 + (int_answer - 58);
			}
			decimal_answer[decimal_index_loop++] = int_answer;
			float_answer = float_answer - int_answer_1;

		}
		decimal_answer[index + index_decimal + 1] = '\0';

	}


	if (number_int != number)
	{
		return decimal_answer;
	}
	else
	{
		return answer;
	}


}

//----------------------- Q2 -----------------------

//make book done
void makeBook(char* text, char***& book, int& totalPages)
{
	int lengthText = 0;
	int lines = 10;
	int character = 41;
	while (text[lengthText] != '\0')
	{
		lengthText++;
	}
	float pages = (static_cast<float>(lengthText) / 410);
	int pagesInt = ((lengthText) / 410);

	if (pages - pagesInt)
	{
		totalPages = pagesInt + 1;
	}
	else
		totalPages = ((lengthText) / 410);


	book = new char** [totalPages];

	for (int i = 0; i < totalPages; i++)
	{
		book[i] = new char* [lines];
		for (int j = 0; j < lines; j++)
		{
			book[i][j] = new char[character];
		}
	}

	int lengthTextPaste = 0;


	for (int i = 0; i < totalPages; i++)
	{
		for (int j = 0; j < lines; j++)
		{
			for (int k = 0; k < character; k++)
			{
				book[i][j][k] = '\0';
			}
		}
	}

	for (int i = 0; i < totalPages; i++)
	{

		for (int j = 0; j < lines; j++)
		{
			for (int k = 0; k < character; k++)
			{

				if (text[lengthTextPaste] == '\0')
					break;
				book[i][j][k] = text[lengthTextPaste++];
			}
		}
	}





}


void cut(char***& book, int totalPages, int FromPage, int ToPage, int FromLine, int ToLine, int FromWord, int ToWord, char*& clipboard)
{

}

void copy(char***& book, int totalPages, int FromPage, int ToPage, int FromLine, int ToLine, int FromWord, int ToWord, char*& clipboard)
{

}

void paste(char***& book, int totalPages, char* clipboard, int atPage, int atLine, int afterWord)
{

}

void Delete(char***& book, int totalPages, int page) // For page deletion
{

}

void Delete(char***& book, int totalPages, int page, int line) //For line deletion
{

}

void DeleteText(char***& book, int totalPages, char* text) //For text deletion
{

}
//Insert done
void insert(char***& book, int& totalPages, int position) // insert empty page after position
{


	int lines = 10;
	int character = 41;
	cout << totalPages << endl;
	int pages = (totalPages - position) + position;
	char*** newBook = new char** [pages];
	for (int i = 0; i < pages; i++)
	{
		newBook[i] = new char* [lines];
		for (int j = 0; j < lines; j++)
		{
			newBook[i][j] = new char[character];
		}
	}
	for (int i = 0; i < pages; i++)
	{

		for (int j = 0; j < lines; j++)
		{
			for (int k = 0; k < character; k++)
			{
				newBook[i][j][k] = book[i][j][k];
			}
		}
	}

	book = newBook;

}

void insert(char***& book, int totalPages, int page, int position) // insert empty line on page
{

}

void insertText(char***& book, int totalPages, int page, int line, int word, char* text)// Insert text after the word.
{

}

void removeDoubleSpaces(char***& book, int& totalPages)
{

}

void concatenateBooks(char***& book1, int totalPages1, char***& book2, int totalPages2, char***& newBook, int& newPages)
{

}

/*char* toString(char***& book, int totalPages) //return book with format given below
{

}*/

//----------------------- Q3 -----------------------
//issafe function
bool isSafeMain(int** board, int row, int col, int queens)
{

	for (int i = 0; i < row; i++)
	{
		if (board[i][col] == 1)
		{
			return false;
		}

	}
	int x = row;
	int y = col;
	while (x >= 0 && y < queens)
	{
		if (board[x][y] == 1)
		{
			return false;
		}
		x--;
		y++;

	}
	x = row;
	y = col;
	while (y >= 0 && x >= 0)
	{
		if (board[x][y] == 1)
		{
			return false;
		}
		x--;
		y--;

	}

	return true;

}
bool royalHarmony(int**& board, int row, int column, int queens)
{

	if (row >= queens)
	{
		return true;
	}



	for (int col = 0; col < queens; col++)
	{
		//recursion
		if (isSafeMain(board, row, col, queens))
		{
			board[row][col] = 1;
			//recursion
			if (royalHarmony(board, row + 1, col, queens))
			{
				return true;
			}
			board[row][col] = 0;
		}
	}

	return false;


}




//----------------------- Q4 -----------------------

//Pattern 1
void RecursivePattern1_help_1(int spaces, int end)
{

	if (end == 0)
		return;
	cout << " ";

	RecursivePattern1_help_1(spaces, end - 1);


}
void RecursivePattern1_help_2(int start, int end)
{
	if (end == 0)
		return;
	if (start == 1)
	{
		RecursivePattern1_help_2(start, end - 1);
		RecursivePattern1_help_1(start, end);
		cout << "*";
		cout << endl;
	}
	if (start == 0)
	{
		RecursivePattern1_help_1(start, end);
		cout << "*";
		cout << endl;
		RecursivePattern1_help_2(start, end - 1);
	}


}

void RecursivePattern1(int start, int end)
{

	if (end == 0)
		return;
	RecursivePattern1_help_2(start, (end / 2));

	if (start == 1)
		RecursivePattern1(start - 1, end - 1);

}
//pattern 2

void RecursiveSpaceStart2(int space, int end)
{
	if (space == 2)
		return;
	cout << " ";
	RecursiveSpaceStart2(space + 1, end);

}

void RecursiveStar2(int start, int end)
{
	if (end == 0)
	{

		return;
	}
	cout << "*";

	RecursiveStar2(start, end - 1);
}


void RecursivePattern2(int start, int end)
{
	if (end == 0)
		return;

	RecursiveSpaceStart2(0, end);
	RecursiveStar2(start, end);
	cout << endl;
	RecursivePattern2(start, end - 1);
	if (end != 1)
		cout << endl;

	RecursiveSpaceStart2(0, end);
	RecursiveStar2(start, end);


}


//----------------------- Q5 -----------------------

struct SavingAccount
{
	char* name;
	float annualInterestRate;
	double savingBalance;
	char* accountNum;

};

void OpenCustomerAccount(SavingAccount* savers[], int& accountsOpen, char* name, float interestRate, double balance) // a function to create a new account and assign it an account number.
{
	savers[accountsOpen] = new SavingAccount;
	if (accountsOpen < 100)
	{
		savers[accountsOpen]->name = name;
		savers[accountsOpen]->savingBalance = balance;
		savers[accountsOpen]->accountNum = new char[5];


		savers[accountsOpen]->accountNum[0] = 'S';
		savers[accountsOpen]->accountNum[1] = 'A';
		savers[accountsOpen]->accountNum[2] = 48 + (accountsOpen / 10);
		savers[accountsOpen]->accountNum[3] = 48 + (accountsOpen % 10);





	}
	else
	{
		cout << "Limit reached maximum " << endl;
	}
	accountsOpen++;
}

float calculateMonthlyInterest(SavingAccount* saver) // that calculates the monthly interest by multiplying the balance by annualInterestRate divided by 12
{
	return (saver->annualInterestRate * saver->savingBalance) / 12;
}

void modifyInterestRate(SavingAccount* saver, float newValue)
{
	saver->annualInterestRate = newValue;
}

int SearchCustomer(SavingAccount* savers[], int accountsOpen, char* accountNum) // a function that searches for an account using an account number. If the customer is found it returns the array index otherwise return -1
{
	if (strlen(accountNum) <= 2)
	{
		for (int i = 0; i < accountsOpen; i++)
		{

			if (savers[i]->accountNum[2] == accountNum[0] && savers[i]->accountNum[3] == accountNum[1])
			{
				return i;

			}

		}

	}
	else
		return -1;



}

bool UpdateAccountBalance(SavingAccount* savers[], int accountsOpen, char* accountNumVal, double balanceVal) // a function that updates a customer’s balance
{
	return savers[accountsOpen]->savingBalance = balanceVal;
}


