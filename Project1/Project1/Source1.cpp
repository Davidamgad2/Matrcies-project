double Det(int row, int col, float mtrx1[100][100], float zmtrx1[100][100], float zmtrx2[100][100], float mtrx2[100][100]) {
     	for (int i = 0; i < row; i++) {
        		for (int j = 0; j < col; j++) {
             			zmtrx1[i][j] = mtrx1[i][j];
            			zmtrx2[i][j] = mtrx2[i][j];
            
        }
        
    }
     	int a, b, c;
    	double d = 1;
     	double div = 0;
     	if (zmtrx1[0][0] == 0) {
         		for (a = 0; a < row; a++) {
            			for (b = 0; b < col; b++) {
                				zmtrx2[a][b] = zmtrx1[a][b];
                
                }
            
        }
        		for (a = 0; a < col; a++) {
             			zmtrx1[0][a] = -zmtrx2[1][a];
            			zmtrx1[1][a] = zmtrx2[0][a];
            
        }
        
            
    }
     	for (a = 0; a < row - 1; a++) {
        		   for (b = 1; b < row; b++) {
             			if (a < b) {
                 				div = zmtrx1[b][a] / zmtrx1[a][a];
                 				for (c = 0; c < col; c++) {
                     					zmtrx1[b][c] = (zmtrx1[b][c] - (div * zmtrx1[a][c]));
                    
                }
                
            }
            
        }
        
    }
     	for (a = 0; a < row; a++) {
        		d *= zmtrx1[a][a];
        
    }