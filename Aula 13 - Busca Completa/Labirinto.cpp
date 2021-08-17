// Labirinto - exemplo de backtracking 

#include<iostream>

using namespace std;

int n = 7;
int m = 6;
char maze[7][6] = {{'.', '#', '#', '.', '.', '.'},
                   {'.', '.', '#', '.', '#', '.'},
                   {'.', '.', '.', '.', '#', '.'},
                   {'#', '.', '#', '.', '.', '.'},
                   {'.', '.', '#', '.', '.', '.'},
                   {'.', '#', '#', '#', '#', '#'},
                   {'.', '.', '.', '.', '.', '.'}};

void printSolution(int i, int j) {
    if (maze[i][j] == '.')
        return;
    if (maze[i][j] == '>')
        printSolution(i, j - 1);
    else if (maze[i][j] == '<')
        printSolution(i, j + 1);
    else if (maze[i][j] == 'v')
        printSolution(i - 1, j);
    else if (maze[i][j] == '^')
        printSolution(i + 1, j);
    cout << '(' << i << ", " << j << ')' << endl;
}

//# i, linha atual
//# j, coluna atual
//# origin, marcador que indica de onde a gente veio
//# rows, número de linhas da matriz
//# columns, número de colunas da matriz
bool solve(int i, int j, char origin, int rows, int columns) {
    //# Verificando se estamos dentro do labirinto
    if (i < 0 or i >= rows)
        return false;
    else if (j < 0 or j >= columns)
        return false;

    //# Verifica se já visitamos a posição (i, j) ou se é uma parede
    else if (maze[i][j] != '.')
        return false;

    maze[i][j] = origin; //# marcar de onde veio e que essa posição já foi visitada

    //# verificando se já chegamos!
    if (i == rows - 1 and j == columns - 1)
        return true;

    return 
           solve(i, j + 1, '>', rows, columns) or //# célula da direita
           solve(i - 1, j, '^', rows, columns) or //# célula de cima
           solve(i + 1, j, 'v', rows, columns) or //# célula de baixo
           solve(i, j - 1, '<', rows, columns);   //# célula da esquerda
           
}

int main() {
    cout << "Labirinto" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "É possível?: " << solve(0, 0, '*', n, m) << endl;
    cout << endl;

    cout << "Posições visitadas" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Caminho percorrido" << endl;
    printSolution(n - 1, m - 1);
}