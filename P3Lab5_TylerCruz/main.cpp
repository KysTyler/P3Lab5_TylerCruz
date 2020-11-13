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

using namespace std;

//prototypes
int** GenerateMatrix(int row,int col);
int** fillMatrixManually(int**& matrix, int row,int col);
int** fillMatrixAutomatically(int**& matrix, int row,int col);
void FreeMatrix(int**& m, int row);
void printMatrix(int**& matrix, int,int);
int** AdditionMatrix(int**& matrixA,int**& matrixB,int size1,int size2);


/*
 * 
 */
int main(int argc, char** argv) {
    int mainOption = 0;
    vector<int**> mainArrayForMatrix;
    vector<int> vectorRow;
    vector<int> vectorCol;
    while(mainOption != 3){
        cout << "*********MENU************" << endl <<
                "Opcion #1 Ingresar matriz" << endl <<
                "Opcion #2 Generar matriz" << endl <<
                "Opcion #3 Realizar operación entre matrices" << endl;
        cout << "Ingrese cual opcion deseas: " << endl;
        cin >> mainOption;
        switch(mainOption){
            case 1:{
                int row,col;
                cout << "Ingrese el size del row del matriz: " << endl;
                cin >> row;
                cout << "Ingrese el size del columna del matriz: " << endl;
                cin >> col;
                int** matrix = NULL;
                matrix = GenerateMatrix(row,col);
                matrix = fillMatrixManually(matrix, row,col);
                
                
                break;
            }
            case 2:{
                int row,col;
                cout << "Ingrese el size del row del matriz: " << endl;
                cin >> row;
                cout << "Ingrese el size del columna del matriz: " << endl;
                cin >> col;
                int** matrix = NULL;
                matrix = GenerateMatrix(row,col);
                matrix = fillMatrixAutomatically(matrix, row,col);
                
                //
                cout << "THIS is in case 2:" << endl;
                printMatrix(matrix,row,col);
                //g1.push_back(i)
                mainArrayForMatrix.push_back(matrix);
                vectorRow.push_back(row);
                vectorCol.push_back(col);
                break;
            }
            case 3:{
                //Print lista de matrices
                for(int i = 0;i<mainArrayForMatrix.size();i++){
                    cout << "Position of vector: " << i << endl;
                    cout << "Position of row: " << vectorRow[i] << endl;
                    cout << "Positon of col: " << vectorCol[i] << endl;
                    printMatrix(mainArrayForMatrix.at(i),vectorRow[i],vectorCol[i]);
                }
                break;
            }
                
                
        }
    }
    return 0;
}

int** GenerateMatrix(int row,int col) {
    if (row > 0 && col > 0) {
        int** intArray = new int*[row];
        for (int i = 0; i < row; i++) {
            intArray[i] = new int[col];
        }
        return intArray;
    }
    return NULL;
}

int** fillMatrixManually(int**& matrix, int row,int col) {
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

int** fillMatrixAutomatically(int**& matrix, int row,int col) {
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

void printMatrix(int**& matrix, int row,int col) {
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

int** AdditionMatrix(int**& matrixA,int**& matrixB,int size1,int size2){
    int** Tempmatrix = NULL;
    Tempmatrix = GenerateMatrix(size1,size2);
    return Tempmatrix;
}

