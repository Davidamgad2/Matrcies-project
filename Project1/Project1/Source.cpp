#include<iostream>
#include<cmath>
#include<string>
using namespace std;
void printmenu() //function to print menu 
{
	cout << "Menu:" << endl;
	cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
	cout << "Select an operation by typing:" << endl;
	cout << "A:For matrix value" << endl;
	cout << "A+B or + : For Addition" << endl;  // multiple inputs are allowed.
	cout << "A-B or B-A Your choice For Subtraction:  " << endl; // multiple inputs are allowed.
	cout << "A*B or B*A your choice For Multiplication  " << endl; //multiple inputs are allowed.
	cout << "A` or B` :For transpose " << endl;
	cout << "A/B or B/A your choice For division:" << endl;
	cout << "Reset:To reset the matrices" << endl; // multiple inputs are allowed.
	cout << "Exit:To exit NOTE THERE WILL BE CONFIRMATION. " << endl; // multiple inputs are allowed.


	cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;

}
void read_mat(string A, float Matrix_A[100][100], int& row_A, int& col_A)
{
	int space = 1;

	int col = 0, row = 0;
	for (int n = 0; n < A.length(); n++)
	{

		if (A[n] == ' ' || A[n] == ']' || A[n] == ';')
		{
			Matrix_A[row][col] = atof(A.substr(space, n - space).c_str());
			space = n + 1;
			if (A[n] == ' ') col++;
			if (A[n] == ';') { row++; col_A = col; col = 0; }
			if (A[n] == ']') row_A = row;
		}

	}
}

void print_mat(float matrix_A[100][100], int& row_A, int& col_A)
{
	for (int i = 0; i <= row_A; i++)
	{
		for (int j = 0; j <= col_A; j++)
		{
			cout << matrix_A[i][j] << "\t";
		}
		cout << endl;
	}

}

void sum_mat(float matrix_A[100][100], float matrix_B[100][100], int& row_A, int& col_A, int& row_B, int& col_B, float matrix_C[100][100]) {

	if (row_A == row_B && col_A == col_B) {
		for (int row = 0; row <= row_A; row++)
		{
			for (int col = 0; col <= col_A; col++) {
				matrix_C[row][col] = matrix_A[row][col] + matrix_B[row][col];

			}

		}
		print_mat(matrix_C, row_A, col_A);
	}
	else cout << "cannot be added";
}

void sub_mat(float matrix_A[100][100], float matrix_B[100][100], int& row_A, int& col_A, int& row_B, int& col_B, float matrix_C[100][100]) {

	if (row_A == row_B && col_A == col_B) {
		for (int row = 0; row <= row_A; row++)
		{
			for (int col = 0; col <= col_A; col++) {
				matrix_C[row][col] = matrix_A[row][col] - matrix_B[row][col];

			}
			print_mat(matrix_C, row_A, col_A);
		}
	}
	else cout << "cannot be subtracted";
}

void multiply_mat(float matrix_A[100][100], float matrix_B[100][100], int row_A, int col_A, int row_B, int col_B, float matrix_result[100][100])
{
	if (col_A == row_B) {
		for (int i = 0; i <= row_A; ++i) {
			for (int j = 0; j <= col_B; ++j) {
				matrix_result[i][j] = 0;
			}
		}
		for (int i = 0; i <= row_A; ++i) {
			for (int j = 0; j <= col_B; ++j) {
				for (int k = 0; k <= col_A; ++k) {
					matrix_result[i][j] += matrix_A[i][k] * matrix_B[k][j];
				}
			}
		}
		print_mat(matrix_result, col_B, row_A);
	}
	else cout << "cannot be multiplied" << endl;
}
float det_mat(float matrix_A[100][100], int row_A, int col_A) {
	float x = 0.0;
	if (row_A != col_A) return 0 && cout << "there is no determinant ";
	if (row_A == 1) {
		x = (matrix_A[0][0] * matrix_A[1][1]) - (matrix_A[0][1] * matrix_A[1][0]);
		return x;
	}
	else {

		float q = matrix_A[0][0] * (matrix_A[2][2] * matrix_A[1][1] - matrix_A[1][2] * matrix_A[2][1]);
		float w = matrix_A[0][1] * (matrix_A[2][2] * matrix_A[1][0] - matrix_A[1][2] * matrix_A[2][0]);
		float e = matrix_A[0][2] * (matrix_A[2][1] * matrix_A[1][0] - matrix_A[1][1] * matrix_A[2][0]);
		return q - w + e;
	}


}
void Trans(float matrix_A[100][100], int& row_A, int& col_A)
{
	for (int a = 0; a < row_A; a++)
	{
		for (int b = 0; b < col_A; b++)
		{
			cout << matrix_A[b][a] << " ";

		}
		cout << endl;
	}
}




int main()
{
	string r, c;
	float matrix_A[100][100];
	float matrix_C[100][100];
	float matrix_B[100][100];
	string B;
	cout << "please enter matrix A  between [] and ; to add new row space to add new col" << endl;
	getline(cin, B);
	int row_B = 0, col_B = 0;
	string C;
	cout << "please enter matrix B between [] and ; to add new row space to add new col" << endl;
	getline(cin, C);
	int row_C = 0, col_C = 0;
	printmenu();

	read_mat(B, matrix_B, row_B, col_B);
	read_mat(C, matrix_C, row_C, col_C);



	do
	{

		cout << "Enter your required operation" << endl;
		cin >> r;

		//add
		if (r == "A+B" || r == "a+b" || r == "B+A" || r == "Add" || r == "add" || r == "+") // multiple enteries for user errors
		{
			cout << "Result of addition is : \n\n" << endl;
			sum_mat(matrix_B, matrix_C, row_B, col_B, row_C, col_C, matrix_A);
			cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
		}
		// For subtraction there are two case : 
		//A-B
		else if (r == "A-B" || r == "a-b" || r == "A - B" || r == "a - b" || r == "subtract" || r == "Subtract" || r == "-")
		{
			cout << "Result of subtractions is : \n\n  " << endl;
			sub_mat(matrix_B, matrix_C, row_B, col_B, row_C, col_C, matrix_A);
			cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
		}
		//B-A
		else if (r == "B-A" || r == "b-a")
		{
			cout << "Result of subtractions is : \n\n  " << endl;
			sub_mat(matrix_C, matrix_B, row_C, col_C, row_B, col_B, matrix_A);
			cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
		}




		//Determinant for A 
		else if (r == "A" || r == "a")
		{
			if (row_B == 1) {
				cout << "det is" << (matrix_B[0][0] * matrix_B[1][1]) - (matrix_B[1][0] * matrix_B[0][1]) << endl;
			}
			else cout << "The determinant for matrix A is " << det_mat(matrix_B, row_B, col_B) << endl;
			cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;

		}
		// determinant for B
		else if (r == "B" || r == "b")
		{
			if (row_C == 1) {
				cout << matrix_C[0][0] * matrix_C[1][1] - matrix_C[1][0] * matrix_C[0][1] << endl;
			}
			else
				cout << "The determinant for matrix B is " << "     " << det_mat(matrix_C, row_C, col_C) << endl;
			cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
		}

		//Multiplication two cases:
			//A*B
		else if (r == "A*B" || r == "a*b" || r == "*")
		{
			cout << "The result of multiplication is: " << "\n\n";
			multiply_mat(matrix_B, matrix_C, row_B, col_B, row_C, col_C, matrix_A);
			cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;

		}
		//B*A
		else if (r == "B*A" || r == "b*a")
		{
			cout << "The result of multiplication is: " << "\n\n";
			multiply_mat(matrix_C, matrix_B, row_C, col_C, row_B, col_B, matrix_A);
			cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
		}

		//Transpose of A 
		else if (r == "TA" || r == "A`" || r == "A'")
		{
			cout << "The Transpose of matrix A is : " << "\n\n";
			Trans(matrix_B, row_B, col_B);
			cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
		}
		//Transpose of B 
		else if (r == "TB" || r == "B`" || r == "B'")
		{
			cout << "The transpose of Matrix B is : " << "\n\n";
			Trans(matrix_C, row_C, col_C);
			cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
		}
		//Division two cases: 
		else if (r == "A/B" || r == "a/b" || r == "/" || r == "divide" || r == "division")
		{
			float D[3][3] = { 0 }, E[100][100] = { 0 };
			// calculate Cofactor 
			D[0][0] = ((matrix_C[1][1] * matrix_C[2][2]) - (matrix_C[2][1] * matrix_C[1][2]));
			D[0][1] = -((matrix_C[1][0] * matrix_C[2][2]) - (matrix_C[2][0] * matrix_C[1][2]));
			D[0][2] = ((matrix_C[1][0] * matrix_C[2][1]) - (matrix_C[2][0] * matrix_C[1][1]));
			D[1][0] = -((matrix_C[0][1] * matrix_C[2][2]) - (matrix_C[2][1] * matrix_C[0][2]));
			D[1][1] = ((matrix_C[0][0] * matrix_C[2][2]) - (matrix_C[2][0] * matrix_C[0][2]));
			D[1][2] = -((matrix_C[0][0] * matrix_C[2][1]) - (matrix_C[2][0] * matrix_C[0][1]));
			D[2][0] = ((matrix_C[0][1] * matrix_C[1][2]) - (matrix_C[1][1] * matrix_C[0][2]));
			D[2][1] = -((matrix_C[0][0] * matrix_C[1][2]) - (matrix_C[1][0] * matrix_C[0][2]));
			D[2][2] = ((matrix_C[0][0] * matrix_C[1][1]) - (matrix_C[1][0] * matrix_C[0][1]));
			// Finding Adjoint
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					E[a][b] = D[b][a];
				}
			}
			//find inverse of C matrix 
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					E[a][b] = E[a][b] / det_mat(matrix_C, row_C, col_C);

				}

			}
			if (det_mat(matrix_C, row_C, col_C) != 0)
			{
				cout << "has no inverse DETER=0";
				multiply_mat(matrix_B, E, row_B, col_B, 3, 3, matrix_A);
				cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
			}
			else
			{
				cout << "Division is not possible \n" << endl;
				cout << "Determinant is equal to zero" << "\n\n";
				cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
			}
		}
		else if (r == "B/A" || r == "b/a")
		{
			float D[3][3] = { 0 }, E[100][100] = { 0 };
			// calculate Cofactor 
			D[0][0] = ((matrix_B[1][1] * matrix_B[2][2]) - (matrix_B[2][1] * matrix_B[1][2]));
			D[0][1] = -((matrix_B[1][0] * matrix_B[2][2]) - (matrix_B[2][0] * matrix_B[1][2]));
			D[0][2] = ((matrix_B[1][0] * matrix_B[2][1]) - (matrix_B[2][0] * matrix_B[1][1]));
			D[1][0] = -((matrix_B[0][1] * matrix_B[2][2]) - (matrix_B[2][1] * matrix_B[0][2]));
			D[1][1] = ((matrix_B[0][0] * matrix_B[2][2]) - (matrix_B[2][0] * matrix_B[0][2]));
			D[1][2] = -((matrix_B[0][0] * matrix_B[2][1]) - (matrix_B[2][0] * matrix_B[0][1]));
			D[2][0] = ((matrix_B[0][1] * matrix_B[1][2]) - (matrix_B[1][1] * matrix_B[0][2]));
			D[2][1] = -((matrix_B[0][0] * matrix_B[1][2]) - (matrix_B[1][0] * matrix_B[0][2]));
			D[2][2] = ((matrix_B[0][0] * matrix_B[1][1]) - (matrix_B[1][0] * matrix_B[0][1]));
			// Finding Adjoint
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					E[a][b] = D[b][a];
				}
			}
			//find inverse of A matrix 
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					E[a][b] = E[a][b] / det_mat(matrix_B, row_B, col_B);

				}

			}
			if (det_mat(matrix_B, row_B, col_B) != 0)
			{
				multiply_mat(matrix_C, E, row_C, col_C, row_B, col_B, matrix_A);
				cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
			}
			else
			{
				cout << "Division is not possible \n" << endl;
				cout << "Determinant is equal to zero" << "\n\n";
				cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
			}
		}

		//exit loop (not to be changed unless urgent) 
		else if (r == "exit" || r == "Exit")
		{
			cout << "\n\n";
			cout << "Are you sure you want to exit? ,type exit if so " << endl;
			cin >> c;
			cout << "\n\n";
			if (c == "exit" || c == "Exit" || c == "yes")
			{
				cout << "THANKS FOR USING OUR SIMPLE PROGRAM " << endl;
				cout << "\t\t\t" << "BYE!" << endl;

				return 0;
			}
			else {

			}
		}

		// reset
		else if (r == "reset" || r == "Reset")
		{
			break;
			break; //break 2 loops to return to redfining matrices. 
			cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;
			cout << "please enter matrix A  between [] and ; to add new row space to add new col" << endl;
			getline(cin, B);
			cout << "please enter matrix B between [] and ; to add new row space to add new col" << endl;
			getline(cin, C);
			printmenu();

			read_mat(B, matrix_B, row_B, col_B);
			read_mat(C, matrix_C, row_C, col_C);
		}


		// Default 
		else
		{
			cout << "Error , Wrong operation or entry " << endl;  // any other operation other than in menu will be error
			cout << "please enter the required operation in a proper format" << endl;
			cout << "\t\t\t" << "###############################################" << "\t\t\t" << endl;

			printmenu();

		}



	} while (true);





	system("pause");
	return 0;
}