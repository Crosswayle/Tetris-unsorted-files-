// ConsoleApplication23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;



HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'
#define ROTATE 'w'

#define FieldWidth 14
#define FieldHeight 24

#define PositionsCount 4 // count of possible rotate positions
#define FigureWidth 4
#define FigureHeight 4

#define FiguresCount 7	 

class Figure
{
private:
	COORD currentCoords; // Coords of figure matrix in field(glass) matrix
	int stepsCount = 0;
	int side = 0;
public:

	void virtual figureElementsInit(int figurePosition = 0) = 0;
	virtual vector<COORD>& GetFigureElements() = 0;
	virtual void clearFigureElements() = 0;
	int& GetStepsCount()
	{
		return stepsCount;
	}

	COORD& GetCurrentCoords()
	{
		return currentCoords;
	}
	int& GetSide()
	{
		return side;
	}

};

class I : public Figure
{
private:
	array<array<array<bool, FigureWidth>, FigureHeight>, PositionsCount> figureMatrix;
	vector<COORD> figureElement; // Coords in figure matrix
public:
	I()
	{
		//Vertical
		figureMatrix[0][0][1] = 1;
		figureMatrix[0][1][1] = 1;
		figureMatrix[0][2][1] = 1;
		figureMatrix[0][3][1] = 1;

		figureMatrix[2][0][1] = 1;
		figureMatrix[2][1][1] = 1;
		figureMatrix[2][2][1] = 1;
		figureMatrix[2][3][1] = 1;

		//Horisontal
		figureMatrix[1][2][0] = 1;
		figureMatrix[1][2][1] = 1;
		figureMatrix[1][2][2] = 1;
		figureMatrix[1][2][3] = 1;

		figureMatrix[3][2][0] = 1;
		figureMatrix[3][2][1] = 1;
		figureMatrix[3][2][2] = 1;
		figureMatrix[3][2][3] = 1;
	}

	void figureElementsInit(int figurePosition = 0)
	{
		COORD tmp;
		for (int y = 0; y < FigureHeight; y++)
		{
			for (int x = 0; x < FigureWidth; x++)
			{
				if (figureMatrix[figurePosition][y][x] == 1)
				{
					tmp.X = x;
					tmp.Y = y;
					figureElement.push_back(tmp);
				}
			}
		}
	}

	void clearFigureElements()
	{
		figureElement.resize(0);
	}

	vector<COORD>& GetFigureElements()
	{
		return figureElement;
	}
};

class L : public Figure
{
private:
	array<array<array<bool, FigureWidth>, FigureHeight>, PositionsCount> figureMatrix;
	vector<COORD> figureElement; // Coords in figure matrix
public:
	L()
	{
		//Vertical
		figureMatrix[0][1][1] = 1;
		figureMatrix[0][2][1] = 1;
		figureMatrix[0][3][1] = 1;
		figureMatrix[0][3][2] = 1;

		figureMatrix[2][1][1] = 1;
		figureMatrix[2][1][2] = 1;
		figureMatrix[2][2][2] = 1;
		figureMatrix[2][3][2] = 1;

		//Horisontal
		figureMatrix[1][2][1] = 1;
		figureMatrix[1][2][2] = 1;
		figureMatrix[1][2][3] = 1;
		figureMatrix[1][1][3] = 1;

		figureMatrix[3][1][3] = 1;
		figureMatrix[3][1][2] = 1;
		figureMatrix[3][1][1] = 1;
		figureMatrix[3][2][1] = 1;
	}

	void figureElementsInit(int figurePosition = 0)
	{
		COORD tmp;
		for (int y = 0; y < FigureHeight; y++)
		{
			for (int x = 0; x < FigureWidth; x++)
			{
				if (figureMatrix[figurePosition][y][x] == 1)
				{
					tmp.X = x;
					tmp.Y = y;
					figureElement.push_back(tmp);
				}
			}
		}
	}

	void clearFigureElements()
	{
		figureElement.resize(0);
	}

	vector<COORD>& GetFigureElements()
	{
		return figureElement;
	}
};

class J : public Figure
{
private:
	array<array<array<bool, FigureWidth>, FigureHeight>, PositionsCount> figureMatrix;
	vector<COORD> figureElement; // Coords in figure matrix
public:
	J()
	{
		//Vertical
		figureMatrix[0][1][1] = 1;
		figureMatrix[0][2][1] = 1;
		figureMatrix[0][3][1] = 1;
		figureMatrix[0][3][0] = 1;

		figureMatrix[2][1][2] = 1;
		figureMatrix[2][1][1] = 1;
		figureMatrix[2][2][1] = 1;
		figureMatrix[2][3][1] = 1;

		//Horisontal
		figureMatrix[1][2][0] = 1;
		figureMatrix[1][2][1] = 1;
		figureMatrix[1][2][2] = 1;
		figureMatrix[1][1][0] = 1;

		figureMatrix[3][1][0] = 1;
		figureMatrix[3][1][1] = 1;
		figureMatrix[3][1][2] = 1;
		figureMatrix[3][2][2] = 1;
	}
	void figureElementsInit(int figurePosition = 0)
	{
		COORD tmp;
		for (int y = 0; y < FigureHeight; y++)
		{
			for (int x = 0; x < FigureWidth; x++)
			{
				if (figureMatrix[figurePosition][y][x] == 1)
				{
					tmp.X = x;
					tmp.Y = y;
					figureElement.push_back(tmp);
				}
			}
		}
	}

	void clearFigureElements()
	{
		figureElement.resize(0);
	}

	vector<COORD>& GetFigureElements()
	{
		return figureElement;
	}
};

class S : public Figure
{
private:
	array<array<array<bool, FigureWidth>, FigureHeight>, PositionsCount> figureMatrix;
	vector<COORD> figureElement; // Coords in figure matrix
public:
	S()
	{
		//Vertical
		figureMatrix[0][0][1] = 1;
		figureMatrix[0][1][1] = 1;
		figureMatrix[0][1][2] = 1;
		figureMatrix[0][2][2] = 1;

		figureMatrix[2][0][1] = 1;
		figureMatrix[2][1][1] = 1;
		figureMatrix[2][1][2] = 1;
		figureMatrix[2][2][2] = 1;

		//Horisontal
		figureMatrix[1][2][0] = 1;
		figureMatrix[1][2][1] = 1;
		figureMatrix[1][1][1] = 1;
		figureMatrix[1][1][2] = 1;

		figureMatrix[3][2][0] = 1;
		figureMatrix[3][2][1] = 1;
		figureMatrix[3][1][1] = 1;
		figureMatrix[3][1][2] = 1;
	}
	void figureElementsInit(int figurePosition = 0)
	{
		COORD tmp;
		for (int y = 0; y < FigureHeight; y++)
		{
			for (int x = 0; x < FigureWidth; x++)
			{
				if (figureMatrix[figurePosition][y][x] == 1)
				{
					tmp.X = x;
					tmp.Y = y;
					figureElement.push_back(tmp);
				}
			}
		}
	}

	void clearFigureElements()
	{
		figureElement.resize(0);
	}

	vector<COORD>& GetFigureElements()
	{
		return figureElement;
	}
};

class Z : public Figure
{
private:
	array<array<array<bool, FigureWidth>, FigureHeight>, PositionsCount> figureMatrix;
	vector<COORD> figureElement; // Coords in figure matrix
public:
	Z()
	{
		//Vertical
		figureMatrix[0][0][2] = 1;
		figureMatrix[0][1][2] = 1;
		figureMatrix[0][1][1] = 1;
		figureMatrix[0][2][1] = 1;

		figureMatrix[2][0][2] = 1;
		figureMatrix[2][1][2] = 1;
		figureMatrix[2][1][1] = 1;
		figureMatrix[2][2][1] = 1;

		//Horisontal
		figureMatrix[1][1][0] = 1;
		figureMatrix[1][1][1] = 1;
		figureMatrix[1][2][1] = 1;
		figureMatrix[1][2][2] = 1;

		figureMatrix[3][1][0] = 1;
		figureMatrix[3][1][1] = 1;
		figureMatrix[3][2][1] = 1;
		figureMatrix[3][2][2] = 1;
	}
	void figureElementsInit(int figurePosition = 0)
	{
		COORD tmp;
		for (int y = 0; y < FigureHeight; y++)
		{
			for (int x = 0; x < FigureWidth; x++)
			{
				if (figureMatrix[figurePosition][y][x] == 1)
				{
					tmp.X = x;
					tmp.Y = y;
					figureElement.push_back(tmp);
				}
			}
		}
	}

	void clearFigureElements()
	{
		figureElement.resize(0);
	}

	vector<COORD>& GetFigureElements()
	{
		return figureElement;
	}
};

class T : public Figure
{
private:
	array<array<array<bool, FigureWidth>, FigureHeight>, PositionsCount> figureMatrix;
	vector<COORD> figureElement; // Coords in figure matrix
public:
	T()
	{
		//Vertical
		figureMatrix[0][1][1] = 1;
		figureMatrix[0][2][1] = 1;
		figureMatrix[0][3][1] = 1;
		figureMatrix[0][2][2] = 1;

		figureMatrix[2][1][2] = 1;
		figureMatrix[2][2][2] = 1;
		figureMatrix[2][3][2] = 1;
		figureMatrix[2][2][1] = 1;

		//Horisontal
		figureMatrix[1][2][1] = 1;
		figureMatrix[1][2][2] = 1;
		figureMatrix[1][2][3] = 1;
		figureMatrix[1][1][2] = 1;

		figureMatrix[3][1][1] = 1;
		figureMatrix[3][1][2] = 1;
		figureMatrix[3][1][3] = 1;
		figureMatrix[3][2][2] = 1;
	}
	void figureElementsInit(int figurePosition = 0)
	{
		COORD tmp;
		for (int y = 0; y < FigureHeight; y++)
		{
			for (int x = 0; x < FigureWidth; x++)
			{
				if (figureMatrix[figurePosition][y][x] == 1)
				{
					tmp.X = x;
					tmp.Y = y;
					figureElement.push_back(tmp);
				}
			}
		}
	}

	void clearFigureElements()
	{
		figureElement.resize(0);
	}

	vector<COORD>& GetFigureElements()
	{
		return figureElement;
	}
};

class Q : public Figure
{
private:
	array<array<array<bool, FigureWidth>, FigureHeight>, PositionsCount> figureMatrix;
	vector<COORD> figureElement; // Coords in figure matrix
public:
	Q()
	{
		//Vertical
		figureMatrix[0][1][1] = 1;
		figureMatrix[0][2][1] = 1;
		figureMatrix[0][1][2] = 1;
		figureMatrix[0][2][2] = 1;

		figureMatrix[2][1][1] = 1;
		figureMatrix[2][2][1] = 1;
		figureMatrix[2][1][2] = 1;
		figureMatrix[2][2][2] = 1;

		//Horisontal
		figureMatrix[1][1][1] = 1;
		figureMatrix[1][2][1] = 1;
		figureMatrix[1][1][2] = 1;
		figureMatrix[1][2][2] = 1;

		figureMatrix[3][1][1] = 1;
		figureMatrix[3][2][1] = 1;
		figureMatrix[3][1][2] = 1;
		figureMatrix[3][2][2] = 1;
	}
	void figureElementsInit(int figurePosition = 0)
	{
		COORD tmp;
		for (int y = 0; y < FigureHeight; y++)
		{
			for (int x = 0; x < FigureWidth; x++)
			{
				if (figureMatrix[figurePosition][y][x] == 1)
				{
					tmp.X = x;
					tmp.Y = y;
					figureElement.push_back(tmp);
				}
			}
		}
	}

	void clearFigureElements()
	{
		figureElement.resize(0);
	}

	vector<COORD>& GetFigureElements()
	{
		return figureElement;
	}
};





class Field
{
private:
	array<array<bool, FieldWidth>, FieldHeight> field = { 0 };

public:
	void printField(int score)
	{
		cout << "  SCORE: " << score << endl;
		for (int i = 4; i<FieldHeight; i++)
		{
			cout << "  ";
			for (int k = 0; k < FieldWidth; k++)
			{
				if (field[i][k] == 0)
				{
					SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE | 0);
					cout << char(177);
				}
				else
				{
					SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 6);
					cout << 'O'; //char(176)
				}

			}
			cout << endl;
		}
	}

	void SetFigureIn(vector<COORD> figureElements, COORD currentMatrixCoords)
	{
		for (auto it_coords : figureElements)
		{
			field[it_coords.Y + currentMatrixCoords.Y][it_coords.X + currentMatrixCoords.X] = true;
		}
	}

	void deleteRow(int pos)
	{
		field[pos] = { 0 };
		for (int y = pos; y > 0; y--)
		{
			field[y] = field[y - 1];
		}
		field[0] = { 0 };
	}

	void IsSomeRowFilled()
	{
		for (int y = 0; y < FieldHeight; y++)
		{
			bool IsFilled = true;
			for (int x = 0; x < FieldWidth; x++)
			{
				if (field[y][x] == false)
				{
					IsFilled = false;
					break;
				}
			}
			if (IsFilled == true)
			{
				deleteRow(y);
			}
		}
	}

	void clearFigure(vector<COORD> figureElements, COORD currentMatrixCoords)
	{
		for (auto it_coords : figureElements)
		{
			field[it_coords.Y + currentMatrixCoords.Y][it_coords.X + currentMatrixCoords.X] = false;
		}
	}

	void figureMoove(Figure *a, char side, bool& IsFallen, int& StepsCount, bool& IsGameOver)
	{
		// It helps me with finding needed elements
		array<array<bool, 4>, 4> tmpFigureMatrix = { 0 };
		for (int i = 0; i < a->GetFigureElements().size(); i++)
		{
			tmpFigureMatrix[a->GetFigureElements()[i].Y][a->GetFigureElements()[i].X] = true;
		}


		if (side == LEFT)
		{
			vector<COORD> leftElements; // needed elements coords vector
			COORD tmp;
			int vectEl_counter = 0;
			// Finding needed elements
			for (int y = FigureHeight - 1; y >= 0; y--)
			{
				bool refresh = false;
				for (int x = FigureWidth - 1; x >= 0; x--)
				{
					if (tmpFigureMatrix[y][x] == true)
					{
						tmp.X = x;
						tmp.Y = y;
						refresh = true;
					}
				}
				if (refresh == true)
				{
					leftElements.push_back(tmp);
					vectEl_counter++;
				}
			} //------------------------

			bool isPossible = true;
			for (int i = 0; i < leftElements.size(); i++)
			{
				COORD abs_coords;
				abs_coords.X = a->GetCurrentCoords().X + leftElements[i].X;
				abs_coords.Y = a->GetCurrentCoords().Y + leftElements[i].Y;
				if (abs_coords.X - 1 < 0 || field[abs_coords.Y][abs_coords.X - 1] == true)
				{
					isPossible = false;
				}
			}
			clearFigure(a->GetFigureElements(), a->GetCurrentCoords());
			if (isPossible == true)
			{
				a->GetCurrentCoords().X -= 1;
				SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
			}
			else
			{
				SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
			}
		}

		if (side == RIGHT)
		{
			vector<COORD> rightElements; // needed elements coords vector

			int vectEl_counter = 0;
			COORD tmp;
			// Finding needed elements
			for (int y = 0; y < FigureHeight; y++)
			{
				bool refresh = false;
				for (int x = 0; x < FigureWidth; x++)
				{

					if (tmpFigureMatrix[y][x] == true)
					{
						tmp.X = x;
						tmp.Y = y;
						refresh = true;
					}

				}
				if (refresh == true)
				{
					rightElements.push_back(tmp);
					vectEl_counter++;
				}
			} //------------------------

			bool isPossible = true;
			for (int i = 0; i < rightElements.size(); i++)
			{
				COORD abs_coords;
				abs_coords.X = a->GetCurrentCoords().X + rightElements[i].X;
				abs_coords.Y = a->GetCurrentCoords().Y + rightElements[i].Y;
				if (abs_coords.X + 1 >= FieldWidth || field[abs_coords.Y][abs_coords.X + 1] == true)
				{
					isPossible = false;
				}
			}
			clearFigure(a->GetFigureElements(), a->GetCurrentCoords());

			if (isPossible == true)
			{
				a->GetCurrentCoords().X += 1;
				SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
			}
			else
			{
				SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
			}
		}

		if (side == DOWN)
		{
			vector<COORD> bottomElements; // needed elements coords vector
			COORD tmp;
			int vectEl_counter = 0;
			// Finding needed elements
			for (int x = 0; x < FigureWidth; x++)
			{
				bool refresh = false;
				for (int y = 0; y <FigureHeight; y++)
				{

					if (tmpFigureMatrix[y][x] == true)
					{
						tmp.X = x;
						tmp.Y = y;
						refresh = true;
					}
				}
				if (refresh == true)
				{
					bottomElements.push_back(tmp);
					vectEl_counter++;
				}
			} //------------------------

			bool isPossible = true;

			for (int i = 0; i < bottomElements.size(); i++)
			{
				COORD abs_coords;
				abs_coords.X = a->GetCurrentCoords().X + bottomElements[i].X;
				abs_coords.Y = a->GetCurrentCoords().Y + bottomElements[i].Y;
				if (abs_coords.Y + 1 >= FieldHeight || field[abs_coords.Y + 1][abs_coords.X] == true)
				{
					isPossible = false;
					break;
				}
			}

			clearFigure(a->GetFigureElements(), a->GetCurrentCoords());

			if (isPossible == true)
			{
				StepsCount++;
				a->GetCurrentCoords().Y += 1;
				SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
			}

			else
			{
				if (StepsCount == 0)
				{
					IsGameOver = true;
				}
				SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
				IsFallen = true;
			}
		}

		if (side == ROTATE)
		{
			//Nbyly cm u jlivfyg qcnb 716 - 720 liqm (linuncha zcaoly)
			clearFigure(a->GetFigureElements(), a->GetCurrentCoords());
			a->clearFigureElements();
			int OriginalSide = a->GetSide();
			if (a->GetSide() == 3)
			{
				OriginalSide = 0;
				a->GetSide() = -1;
			}

			a->figureElementsInit(a->GetSide() + 1);

			bool IsPossible = true;
			for (int i = 0; i < 4; i++)
			{
				COORD abs_coord;
				abs_coord.X = a->GetCurrentCoords().X + a->GetFigureElements()[i].X;
				abs_coord.Y = a->GetCurrentCoords().Y + a->GetFigureElements()[i].Y;
				if (abs_coord.X >= FieldWidth || abs_coord.X <= 0 || abs_coord.Y>=FieldHeight)
				{
					IsPossible = false;
				}

				else if (field[abs_coord.Y][abs_coord.X] == true)
				{
					IsPossible = false;

				}
			}

			if (IsPossible == true)
			{
				a->clearFigureElements();
				a->figureElementsInit(a->GetSide() += 1);
				SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
			}
			else
			{
				a->clearFigureElements();
				a->figureElementsInit(OriginalSide);
				SetFigureIn(a->GetFigureElements(), a->GetCurrentCoords());
			}
		}
	}

	auto GetField()
	{
		return field;
	}
};



class Game
{
private:
	Game()
	{

	}
	~Game()
	{

	}
	Game(const Game&)
	{

	}
	Game operator=(const Game&)
	{

	}
	//----------------------------------
	int FigureMoovingSpeed = 9;
	Figure* randFigure()
	{
		int random = rand() % 7 + 1;
		if (random == 1)
		{
			return new I();
		}
		else if (random == 2)
		{
			return new L();
		}
		else if (random == 3)
		{
			return new J();
		}
		else if (random == 4)
		{
			return new S();
		}
		else if (random == 5)
		{
			return new Z();
		}
		else if (random == 6)
		{
			return new Q();
		}
		else if (random == 7)
		{
			return new T();
		}
	}

	int score = 0 - 1;

public:
	void SetScore(int k = 1)
	{
		score += k;
	}

	static Game& GetInstance()
	{
		static Game Tetris;
		return Tetris;
	}

	int GetScore()
	{
		return score;
	}

	void GameOverPrint()
	{
		system("mode con:cols=60 lines=10");
		SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | 0);
		cout << "  _____   ___  ___  ___ _____   _____  _   _ ___________" << endl;
		cout << " |  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | |  ___| ___ \\" << endl;
		cout << " | |  \\// /_\\ \\| .  . || |__   | | | || | | | |__ | |_/ /" << endl;
		cout << " | |_\\ \\| | | || |\\/| || |___  \\ \\_/ /\\ \\_/ / |___| |\\ \\ " << endl;
		cout << "  \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/\\____/\\_| \\_|" << endl;
		cout << endl;
		SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 4);
		cout << "                    YOUR SCORE: ";
		Sleep(5000);
		cout << GetScore() << endl;
		SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 7);
		cout << endl << endl;
	}

	int& GetFigureMoovingSpeed()
	{
		return FigureMoovingSpeed;
	}

	void MoovingSpeedEditing()
	{
		if (GetScore() % 15 == 0 && FigureMoovingSpeed>5)
		{
			FigureMoovingSpeed--;
		}
	}



	void TetrisGame()
	{
		bool IsFallen = false;
		bool IsStart = true;
		bool IsGameOver = false;
		Field glass;
		Figure *figure = randFigure();
		char side;
		int CycleRoundsCounter = 0;
		while (IsGameOver == false)
		{
			if (IsFallen == true || IsStart == true)
			{
				SetScore();
				IsStart = false;
				IsFallen = false;
				figure = randFigure();
				figure->figureElementsInit();
				figure->GetCurrentCoords().X = rand() % 11;
				figure->GetCurrentCoords().Y = 0;
				figure->GetStepsCount() = 0;
			}


			glass.SetFigureIn(figure->GetFigureElements(), figure->GetCurrentCoords());

			glass.printField(GetScore());

			Sleep(30);
			if (_kbhit() == true)
			{
				side = _getch();
				glass.figureMoove(figure, side, IsFallen, figure->GetStepsCount(), IsGameOver);
			}

			
			if (CycleRoundsCounter%GetFigureMoovingSpeed()==0)
			{
				glass.figureMoove(figure, DOWN, IsFallen, figure->GetStepsCount(), IsGameOver);
			}
			if (IsFallen == true)
			{
				glass.IsSomeRowFilled();
			}
			CycleRoundsCounter++;
			MoovingSpeedEditing();
			system("cls");
		}

		GameOverPrint();
	}
};

int main()
{

	system("color 0F");
	srand(time(0));


	system("mode con:cols=34 lines=5");
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE | 5);
	cout << " W - rotate figure" << endl;
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 0);
	cout << " A - moove left" << endl;
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | 2);
	cout << " S - moove down" << endl;
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE | 8);
	cout << " D - moove right" << endl;
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 5);
	cout << " > Press any key to start game" << endl;
	_getch();

	system("mode con:cols=18 lines=22");
	Game& Tetris = Game::GetInstance();
	Tetris.TetrisGame();


	//figure.PrintFigure();
	//figure.PrintFigureElements();


	return 0;
}
