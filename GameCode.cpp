#include<iostream>
#include<fstream>
using namespace std;
void read(char file[], char rar[][15]);
void display(char arr[][15], int s, int tri);
void pause_s(char  grid[][15], int score, int tries, char hint, int loop);
void resume();
bool diagnol_c(char grid[][15], char key[], int chk);                //  Checking to match the word in diaonal direction 
bool diagnol_r(char grid[][15], char search[], int chk);             //Checking to match the word in diaonal reverse direction
bool diagnol_l(char grid[][15], char search[], int chk);
bool  diagnol_rh(char grid[][15], char search[], int chk);
bool  diagnol_lh(char grid[][15], char search[], int chk);
void high_check();
void s_high(int score);
bool check_r(char grid[][15], char key[], int chk);
bool check_c(char grid[][15], char key[], int chk);
void reverse(char rev[], int chk);
void easy(int score, int lives, int loop);
void medium(int score, int lives, int loop);
void hard(int score, int lives, int loop);
//all the prototypes which are used
void read(char file[], char rar[][15])         //First step to read the file 
{
	ifstream fin;
	fin.open(file);
	for (int row = 0; row< 15; row++)
	{
		for (int col = 0; col < 15; col++)
		{
			fin >> rar[row][col];
		}
	}
}
void display(char arr[][15], int s, int tri)                       //Displaying the readed file 
{
	system("color 06");
	cout << "\t\t\t                     WORD SEARCH GAME            " << endl;
	cout << "\t\t\t------------------------------------------------------------" << endl;
	for (int row = 0; row< 15; row++)
	{
		cout << "\t\t\t|";
		for (int col = 0; col < 15; col++)
		{
			cout << arr[row][col] << " | ";
		}
		cout << endl;
	}
	cout << "\t\t\t------------------------------------------------------------" << endl;
	cout << "SCORE :" << s << "\t\t\t\t\t\t\t\t\t TRIES :" << tri << endl;
	cout << "\t\t\t\t\tBy M.HUSNAIN NAEEM" << endl<<endl;
}
void pause_s(char  grid[][15], int score, int tries, char hint, int loop)
{
	int x, y;
	ofstream fout;
	ifstream fin;
	fin.open("Pause.txt");
	fout.open("Pause.txt");

	for (x = 0; x < 15; x++)
	{
		for (y = 0; y < 15; y++)
		{
			fout << grid[x][y];
		}
		cout << endl;
	}
	fout << score << " " << tries << " " << hint << " " << loop;
	fin.close();
	fout.close();
}
void resume()
{
	int x, y, score, tries, loop;
	char hint;
	char grid[15][15];
	ifstream fin;
	char ar[] = { "Pause.txt" };
	fin.open(ar);
	for (x = 0; x < 15; x++)
	{
		for (y = 0; y < 15; y++)
		{
			fin >> grid[x][y];
		}
	}
	fin >> score;
	fin >> tries;
	fin >> hint;
	fin >> loop;
	if (hint == 'e')
	{
		easy(score, tries, loop);
	}
	if (hint == 'm')
	{
		medium(score, tries, loop);
	}
	if (hint == 'h')
	{
		hard(score, tries, loop);
	}
}
bool diagnol_c(char grid[][15], char key[], int chk)
{
	int x, y, c;
	int match = 1;
	bool kkk = false;
	for (x = 0; x < 15; x++)
	{
		if (grid[x][x] == key[0])
		{
			c = 1;
			for (y = x + 1; c != chk; y++)
			{
				if (grid[y][y] == key[c])
				{
					match++;
				}
				c++;
			}
			if (match == chk&&c == chk)
			{
				kkk = true;
				match = 1;
			}
			else
				match = 1;

		}

	}
	return kkk;
}
void high_check()
{
	int hi[5], x;
	ifstream fin;
	fin.open("Highscore.txt");
	for (x = 0; x < 5; x++)
	{
		fin >> hi[x];
	}
	system("cls");
	system("color 09");
	cout << "\t\t\tHE HIGH SCORES ARE GIVEN BELOW" << endl << endl;
	for (x = 0; x < 5; x++)
	{
		cout << "High score is" << hi[x] << endl;
	}
	fin.close();
}
void s_high(int score)
{
	int h_arr[6], x, y, temp;
	ifstream fin;
	fin.open("Highscore.txt");
	for (x = 0; x < 5; x++)
	{
		fin >> h_arr[x];
	}
	h_arr[5] = score;
	for (x = 0; x < 6; x++)
	{
		for (y = x + 1; y < 6; y++)
		{
			if (h_arr[x] < h_arr[y])
			{                                //HERE WE ENTER ALL RECORD AND THE SORT INTO 5 THEN REMOVE THE LATS ONE 
				temp = h_arr[x];
				h_arr[x] = h_arr[y];
				h_arr[y] = temp;
			}
		}
	}
	ofstream fout;
	fout.open("Highscore.txt");
	for (x = 0; x < 5; x++)
	{
		fout << h_arr[x] << " ";
	}
	fout.close();
}
bool check_r(char grid[][15], char key[], int chk)
{
	int x, y;
	int match = 1;
	bool kkk = false;                                //check end the program for the search found or not
	int c;                                         //control the loop for the word match
	for (x = 0; x < 15; x++)
	{
		for (y = 0; y < 15; y++)
		{
			if (key[0] == grid[x][y])        //match first word
			{
				c = 1;
				for (int k = y + 1; c != chk; k++)          // mtch the whole wrd nxt
				{

					if (grid[x][k] == key[c])
					{
						match++;
					}

					c++;
				}
				if (match == chk&&c == chk)
				{
					kkk = true;
					match = 1;

				}
				else
				{
					match = 1;
				}
			}
		}
	}
	return kkk;

}
bool check_c(char grid[][15], char key[], int chk)//SEARCHING IN COLUMN
{
	int col, row;
	int match = 1;
	bool kkk = false;                                //check end the program for the search found or not
	int c;                                         //control the loop for the word match
	for (col = 0; col < 15; col++)
	{
		for (row = 0; row < 15; row++)
		{
			if (key[0] == grid[row][col])        //match first word
			{
				c = 1;
				for (int k = row + 1; c != chk; k++)          // mtch the whole wrd nxt
				{

					if (grid[k][col] == key[c])
					{
						match++;
					}
					c++;
				}
				if (match == chk&&c == chk)
				{
					kkk = true;
					match = 1;

				}
				else
					match = 1;
			}
		}
	}                                                      // SHIFTING ROW AND COLUMNS
	return kkk;

}
bool diagnol_r(char grid[][15], char search[], int chk)//clear
{
	int  j, k, m1, m2, m3, x, y = 0, match = 1, c;
	bool kkk = false;
	for (x = 1; x < 15; x++)
	{
		for (j = y, k = x; k < 15; j++, k++)
		{
			//    This funtion chk the the griD in right half diagnols 
			if (grid[j][k] == search[0])
			{

				for (m1 = j + 1; m1<15; m1++)
				{
					c = 1;
					for (m2 = m1, m3 = k + 1; c != chk; m2++, m3++)
					{

						if (search[c] == grid[m2][m3])
						{
							match++;
						}
						c++;
					}
				}
				if (match == chk&&c == chk)
				{
					kkk = true;
					match = 1;
				}
				else
					match = 1;

			}
		}

	}
	return kkk;
}
bool diagnol_l(char grid[][15], char search[], int chk)
{                                              //     THIS FUNCTION MATCHES THE WORD FROM THE LEFT HALF DIAGOLS
	int x, y, j, k, m1, m2, c = 0, match = 1, m3;
	y = 0;
	bool kkk = false;
	for (x = 1; x < 15; x++)
	{
		for (j = x, k = y; j < 15; j++, k++)
		{
			if (grid[j][k] == search[0])
			{
				cout << k;

				for (m1 = j + 1; m1<15; m1++)
				{
					c = 1;
					for (m2 = m1, m3 = k + 1; c != chk; m2++, m3++)
					{

						if (search[c] == grid[m2][m3])
						{
							match++;
						}
						c++;
					}
				}
				if (match == chk&&c == chk)
				{
					kkk = true;
					match = 1;                                               //else bhi ad kr dna bad ma  ---fazool admi 
				}
				else
					match = 1;
			}
		}
	}
	return kkk;
}
bool diagnol_lh(char grid[][15], char search[], int chk)
{
	int x, y = 0, j, k, m1, m2, c = 0, match = 1;
	bool kkk = false;
	for (x = 13; x >= 0; x--)
	{
		for (j = x, k = 0; j >= k; j--, k++)
		{
			if (grid[k][j] == search[0])
			{
				c = 1;
				for (m1 = x - 1, m2 = k + 1; c != chk; m1--, m2++)
				{
					if (grid[m2][m1] == search[c])
					{
						match++;
					}
					c++;
				}

			}
		}
		if (chk == match)
		{
			kkk = true;
			match = 1;
		}
		else
			match = 1;
	}
	return kkk;

}
bool  diagnol_rh(char grid[][15], char search[], int chk)
{
	int x, y = 0, j, k, m1, m2, c = 0, match = 1;
	bool kkk = false;
	for (x = 0; x < 15; x++)
	{
		for (j = 14, k = x; j >= x; j--, k++)
		{
			if (grid[k][j] == search[0])
			{
				c = 1;
				for (m1 = j - 1, m2 = x + 1; c != chk; m1--, m2++)
				{
					if (grid[m2][m1] == search[c])
					{
						match++;
					}
					c++;
				}

			}
		}
		if (chk == match)
		{
			kkk = true;
			match = 1;
		}
		else
			match = 1;

	}
	return kkk;
}

void reverse(char rev[], int chk)
{
	int x, y;
	char arr[10];
	for (x = 0; x < chk; x++)
	{
		arr[x] = rev[x];
	}
	for (x = 0, y = chk - 1; x<chk, y >= 0; y--, x++)
	{
		rev[x] = arr[y];
	}
	cout << rev;
}
int getl(char w_s[], int chk = 0)
{
	while (w_s[chk] != '\0')
	{
		chk++;
	}
	return chk;
}
bool hrev(char grid[][15], char w_s[], int chk)
{
	bool correct = false;
	reverse(w_s, chk);
	correct = check_c(grid, w_s, chk);
	if (correct == false)
	{
		correct = check_r(grid, w_s, chk);

	}

	if (correct == false)            //all diagnols entries
	{
		if (correct == false)
		{
			correct = diagnol_l(grid, w_s, chk);
		}
		if (correct == false)
		{
			correct = diagnol_r(grid, w_s, chk);
		}
	}
	if (correct == false)               //   simple diagnol 
	{
		correct = diagnol_c(grid, w_s, chk);
	}
	if (correct == false)       //In this codition we chk the anti-diagnol entries
	{
		if (correct == false)
		{
			correct = diagnol_lh(grid, w_s, chk);
		}
		if (correct == false)
		{
			correct = diagnol_rh(grid, w_s, chk);
		}
	}
	return correct;
}
bool ver_w(char word[], int size)
{
	ifstream fin;
	char check_word[15];
	bool kkk = false;


	fin.open("dictionary.txt", ios::in);
	while (!fin.eof())
	{
		fin >> check_word;

		int size2 = strlen(check_word);
		if ((size == 1))
			continue;
		if (word[0] == check_word[0] && size == size2)
		{
			for (int i = 0; word[i] != '\0'; i++)
			{
				if (word[i] != check_word[i])
				{
					break;
				}
			}
			kkk = true;
			break;
		}
	}
	fin.close();

	return kkk;
}
void easy(int score, int lives, int loop)
{
	bool correct = false,dic=false;
	int chk;
	char file[10] = { "Board.txt" };
	char grid[15][15], w_s[15], achk = NULL;
	read(file, grid);
	while (lives != 0 && loop >= 0)//Words you want to search
	{
		system("cls"); //
		display(grid, score, lives);
		cout << "Enter the word to search :";
		cin >> w_s;
		if ((w_s[0] == 'p' || w_s[0] == 'P') && w_s[1] == '\0')
		{
			pause_s(grid, score, lives, 'e', loop);
			cout << "Press E to Exit or Press R to Resume........ " << endl;
			while (achk != 'E' && achk != 'e' && achk != 'r' && achk != 'R')
			{
				cin >> achk;
			}
			if (achk == 'r' || achk == 'R')
			{
				continue;
			}
			if (achk == 'E' || achk == 'e')
			{
				break;
			}
		}
			chk = 0;
			chk = getl(w_s, chk);
			dic = ver_w(w_s, chk);
			if (dic == true)
			{
				dic = false;
				correct = check_c(grid, w_s, chk);
				if (correct == false)
				{
					correct = check_r(grid, w_s, chk);

				}
			}
		if (correct == true)
		{
			score = score + 10;
			loop--;
			correct = false;
		}
		else
		{
			lives--;
		}
	}
	s_high(score);
	system("cls"); //
	display(grid, score, lives);
	system("pause");
}
void medium(int score, int lives, int loop)
{
	bool correct = false,dic=false;
	int chk;
	char file[10] = { "Board.txt" };
	char grid[15][15], w_s[15], achk = NULL;
	read(file, grid);
	while (lives != 0 && loop >= 0)//Words you want to search
	{
		system("cls"); //
		display(grid, score, lives);
		cout << "Enter the word to search :";
		cin >> w_s;
		if (w_s[0] == 'p' || w_s[0] == 'P')
		{
			pause_s(grid, score, lives, 'm', loop);
			cout << "Press E to Exit or Press R to Resume........ " << endl;
			achk = NULL;
			while (achk != 'E' && achk != 'e' && achk != 'r' && achk != 'R')
			{
				cin >> achk;
			}
			if (achk == 'r' || achk == 'R')
			{
				continue;
			}
			if (achk == 'E' || achk == 'e')
			{
				break;
			}
		}
		chk = 0;
		chk = getl(w_s, chk);
		dic = ver_w(w_s, chk);
		if (dic == true)
		{
			correct = check_c(grid, w_s, chk);
			if (correct == false)
			{
				correct = check_r(grid, w_s, chk);

			}
			if (correct == false)
			{
				reverse(w_s, chk);
				correct = check_c(grid, w_s, chk);
				if (correct == false)
				{
					correct = check_r(grid, w_s, chk);

				}
			}
		}
		if (correct == true)
		{
			score = score + 10;
			loop--;
			correct = false;
		}
		else
		{
			lives--;
		}
	}
	s_high(score);
	system("cls"); //
	display(grid, score, lives);
	system("pause");
}
void hard(int score, int lives, int loop)
{
	bool correct = false,dic=false;
	int chk;
	char file[10] = { "Board.txt" };
	char grid[15][15], w_s[15], achk = NULL;
	read(file, grid);
	while (lives != 0 && loop >= 0)//Words you want to search
	{
		system("cls"); //
		display(grid, score, lives);
		cout << "Enter the word to search :";
		cin >> w_s;
		if ((w_s[0] == 'p' || w_s[0] == 'P') && w_s[1] == '\0')
		{
			pause_s(grid, score, lives, 'h', loop);
			cout << "Press E to Exit or Press R to Resume........ " << endl;
			achk = NULL;
			while (achk != 'E' && achk != 'e' && achk != 'r' && achk != 'R')

			{
				cin >> achk;
			}
			if (achk == 'r' || achk == 'R')
			{
				continue;
			}
			if (achk == 'E' || achk == 'e')
			{
				break;
			}

		}
		chk = 0;
		chk = getl(w_s, chk);
		dic = ver_w(w_s, chk);
		if (dic == true)
		{
			correct = check_c(grid, w_s, chk);
			if (correct == false)
			{
				correct = check_r(grid, w_s, chk);

			}

			if (correct == false)            //all diagnols entries
			{
				if (correct == false)
				{
					correct = diagnol_l(grid, w_s, chk);
				}
				if (correct == false)
				{
					correct = diagnol_r(grid, w_s, chk);
				}
			}
			if (correct == false)               //   simple diagnol 
			{
				correct = diagnol_c(grid, w_s, chk);
			}
			if (correct == false)       //In this codition we chk the anti-diagnol entries
			{
				if (correct == false)
				{
					correct = diagnol_lh(grid, w_s, chk);
				}
				if (correct == false)
				{
					correct = diagnol_rh(grid, w_s, chk);
				}
			}
			if (correct == false)    //This condition chk all the diagnol and other values in reverse order
			{
				correct = hrev(grid, w_s, chk);
			}
		}
		////////////
		if (correct == true)
		{
			score = score + 10;
			loop--;
			correct = false;
		}

		else
		{
			lives--;
		}
	}
	s_high(score);
	system("cls"); //
	display(grid, score, lives);
	system("pause");

}

int main() 
{
	char choice;
	bool kkk = false;
	int  chk = 0;             //chk is for the length of the word
	ifstream fin;
	cout << "\t\t\t WORD SEARCH GAME " << endl << endl;
	cout << "MENUE : \n";
	cout << "Press N for new game \nPress R for resume game \nPress L for level selection \nPress H for High score check up \nPress E for exit " << endl;
	cin >> choice;

	if (choice == 'r' || choice == 'R')
	{
		resume();
	}
	if (choice == 'e' || choice == 'E')
	{
	}
	if (choice == 'l' || choice == 'L')
	{
		int lvl;
		cout << "Press 1 for Easy Mode" << endl;
		cout << "Press 2 for Medium Mode" << endl;
		cout << "Press 3 for Hard Mode" << endl;
		cin >> lvl;
		if (lvl == 1)
		{
			easy(0, 3, 5);
		}
		if (lvl == 2)
		{
			medium(0, 3, 7);
		}
		if (lvl == 3)
		{
			hard(0, 3, 15);
		}
	}
	if (choice == 'h' || choice == 'H')
	{
		high_check();
	}
	if (choice == 'N' || choice == 'n')
	{
		int lvl1;
		cout << "PLEASE SELECT THE LEVEL OF THE GAME " << endl << endl;
		cout << "Press 1 for Easy Mode" << endl;
		cout << "Press 2 for Medium Mode" << endl;
		cout << "Press 3 for Hard Mode" << endl;
		cin >> lvl1;
		if (lvl1 == 1)
		{
			easy(0, 3, 5);
		}
		if (lvl1 == 2)
		{
			medium(0, 3, 7);
		}
		if (lvl1 == 3)
		{
			hard(0, 3, 15);
		}
	}
}
