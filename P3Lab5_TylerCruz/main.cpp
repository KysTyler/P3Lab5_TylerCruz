/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tyler C
 *
 * Created on November 13, 2020, 12:52 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//prototypes
int** GenerateMatrix(int row, int col);
int** fillMatrixManually(int**& matrix, int row, int col);
int** fillMatrixAutomatically(int**& matrix, int row, int col);
void FreeMatrix(int**& m, int row);
void printMatrix(int**& matrix, int, int);
int** AdditionMatrix(int**& matrixA, int**& matrixB, int size);
int** SubtractionMatrix(int**& matrixA, int**& matrixB, int size);
int** multOfMatrix(int**& matrixA, int**& matrixB, int rowM1, int colM1, int rowM2, int colM2);

/*
 * 
 */
int main(int argc, char** argv) {
    int mainOption = 0;
    vector<int**> mainArrayForMatrix;
    vector<int> vectorRow;
    vector<int> vectorCol;
    while (mainOption != 3) {
        cout << "*********MENU************" << endl <<
                "Opcion #1 Ingresar matriz" << endl <<
                "Opcion #2 Generar matriz" << endl <<
                "Opcion #3 Realizar operación entre matrices" << endl;
        cout << "Ingrese cual opcion deseas: " << endl;
        cin >> mainOption;
        switch (mainOption) {
            case 1:
            {
                int row, col;
                cout << "Ingrese el size del row del matriz: " << endl;
                cin >> row;
                cout << "Ingrese el size del columna del matriz: " << endl;
                cin >> col;
                int** matrix = NULL;
                matrix = GenerateMatrix(row, col);
                matrix = fillMatrixManually(matrix, row, col);


                break;
            }
            case 2:
            {
                int row, col;
                cout << "Ingrese el size del row del matriz: " << endl;
                cin >> row;
                cout << "Ingrese el size del columna del matriz: " << endl;
                cin >> col;
                int** matrix = NULL;
                matrix = GenerateMatrix(row, col);
                matrix = fillMatrixAutomatically(matrix, row, col);

                //just for seeing the created matrix
                cout << "THIS is in case 2:" << endl;
                printMatrix(matrix, row, col);


                //g1.push_back(i)
                mainArrayForMatrix.push_back(matrix);
                vectorRow.push_back(row);
                vectorCol.push_back(col);
                break;
            }
            case 3:
            {
                
                string operation = "";
                //Print lista de matrices
                for (int i = 0; i < mainArrayForMatrix.size(); i++) {
                    cout << "Position of vector: " << i << endl;
                    cout << "Position of row: " << vectorRow[i] << endl;
                    cout << "Positon of col: " << vectorCol[i] << endl;
                    printMatrix(mainArrayForMatrix.at(i), vectorRow[i], vectorCol[i]);
                }
                cout << "Ingrese la operacion que deseas realiza: " << endl;
                cin >> operation;
                //cout << "Operation: " << operation << endl;
                string pos1 = "", pos2 = "";
                for (int i = 0; i < operation.size(); i++) {
                    if (operation[i] == '*') {
                        for (int j = i - 1; j >= 0; j--) {
                            if (operation[j] == '*' || operation[j] == '+' || operation[j] == '-') {
                                //cout << "D: " <<operation[j] << endl;
                                //cout<<"break1"<<endl;
                                break;
                            }
                            if (operation[j] != '*' && operation[j] != '+' && operation[j] != '-') {
                                pos1 += operation[j];
                            }
                        }
                        for (int l = i + 1; l < operation.size(); l++) {
                            if (operation[l] == '*' || operation[l] == '+' || operation[l] == '-') {
                                //cout << "P: " <<operation[l] << endl;
                                //cout << "break2" << endl;
                                break;
                            }
                            if (operation[l] != '*' && operation[l] != '+' && operation[l] != '-') {
                                pos2 += operation[l];
                            }
                        }
                    }
                }
                cout << "Pos1" << pos1 << endl;
                cout << "Pos2" << pos2 << endl;
                int newPos1 = stoi(pos1);
                int newPos2 = stoi(pos2);
                if(newPos1 < 0 || newPos1 > mainArrayForMatrix.size()){
                    cout << "Cannot do beacuase positions are not part of the vector!" <<endl;
                }else if(newPos2 < 0 || newPos2 > mainArrayForMatrix.size()){
                    cout << "Cannot do beacuase positions are not part of the vector!" <<endl;
                }
                
                
                int** resultM = multOfMatrix(mainArrayForMatrix.at(newPos1), mainArrayForMatrix.at(newPos2), vectorRow[newPos1], vectorCol[newPos1], vectorRow[newPos2], vectorCol[newPos2]);
                printMatrix(resultM, vectorRow[0], vectorCol[1]);
                
                
                
                //FreeMatrix(int**& m, int row)
                for (int i = 0; i << mainArrayForMatrix.size(); i++) {
                    FreeMatrix(mainArrayForMatrix.at(i), vectorRow[i]);
                }


                break;
            }
                //            case 4:
                //            {
                //                //this is just a practice case
                //                multOfMatrix(int**& matrixA, int**& matrixB, int rowM1, int colM1, int rowM2, int colM2)
                //                cout << "First matrix: " << endl;
                //                printMatrix(mainArrayForMatrix.at(0), vectorRow[0], vectorCol[0]);
                //                cout << "Second matrix: " << endl;
                //                printMatrix(mainArrayForMatrix.at(1), vectorRow[1], vectorCol[1]);
                //                cout << "Result: " << endl;
                //
                //                int** resultM = multOfMatrix(mainArrayForMatrix.at(0), mainArrayForMatrix.at(1), vectorRow[0], vectorCol[0], vectorRow[1], vectorCol[1]);
                //                printMatrix(resultM, vectorRow[0], vectorCol[1]);
                //                
                //                int** AdditionMatrix(int**& matrixA, int**& matrixB, int size)
                //                int ** resultM = SubtractionMatrix(mainArrayForMatrix.at(0), mainArrayForMatrix.at(1),3);
                //                printMatrix(resultM, vectorRow[0], vectorCol[1]);
                //                for(int i = 0;i<< mainArrayForMatrix.size();i++){
                //                    FreeMatrix(mainArrayForMatrix.at(i),vectorRow[i]);
                //                }
                //                break;
                //            }

        }
    }
    return 0;
}

int** GenerateMatrix(int row, int col) {
    if (row > 0 && col > 0) {
        int** intArray = new int*[row];
        for (int i = 0; i < row; i++) {
            intArray[i] = new int[col];
        }
        return intArray;
    }
    return NULL;
}

int** fillMatrixManually(int**& matrix, int row, int col) {
    if (row > 0 && col > 0 && matrix != NULL) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int x;
                cout << "Ingrese el valor x de la posicion [" << i << "]" << "[" << j << "]" << endl;
                cin >> x;
                matrix[i][j] = x;
            }
        }
    }
    return matrix;
}

int** fillMatrixAutomatically(int**& matrix, int row, int col) {
    if (row > 0 && col > 0 && matrix != NULL) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = (rand() % 101) - 49;
            }
        }
    }
    return matrix;
}

void FreeMatrix(int**& m, int row) {
    if (m != NULL && row > 0) {
        for (int i = 0; i < row; i++) {
            if (m[i] != NULL) {
                delete[] m[i];
                m[i] = NULL;
            }
        }
        delete[] m;
        m = NULL;
    }
}

void printMatrix(int**& matrix, int row, int col) {
    if (row > 0 && col > 0 && matrix != NULL) {
        for (int i = 0; i < row; i++) {
            if (matrix[i] != NULL) {
                for (int j = 0; j < col; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
}

int** AdditionMatrix(int**& matrixA, int**& matrixB, int size) {
    int** Tempmatrix = NULL;
    Tempmatrix = GenerateMatrix(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Tempmatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return Tempmatrix;
}

int** SubtractionMatrix(int**& matrixA, int**& matrixB, int size) {
    int** Tempmatrix = NULL;
    Tempmatrix = GenerateMatrix(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Tempmatrix[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return Tempmatrix;
}

int** multOfMatrix(int**& matrixA, int**& matrixB, int rowM1, int colM1, int rowM2, int colM2) {
    int** Tempmatrix = NULL;
    if (colM1 == rowM2) {
        Tempmatrix = GenerateMatrix(colM1, rowM2);
        for (int i = 0; i < rowM1; i++) {
            for (int j = 0; j < colM2; j++) {
                Tempmatrix[i][j] = 0;
                for (int k = 0; k < colM1; k++) {
                    Tempmatrix[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
    }

    return Tempmatrix;
}




