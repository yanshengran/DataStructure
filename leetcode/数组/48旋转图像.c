void rotate(int** matrix, int matrixSize, int* matrixColSize){//先转置后左右翻转
    int tep = 0;
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < i; j++){
            tep = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tep;
        }
    }
    for(int k = 0; k < matrixSize; k++){
        for(int l = 0; l < matrixColSize[0]/2; l++){
            tep = matrix[k][l];
            matrix[k][l] = matrix[k][matrixColSize[0]-1-l];
            matrix[k][matrixColSize[0]-1-l] = tep;
        }
    }
}
