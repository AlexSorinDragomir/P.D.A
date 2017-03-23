package matrix.multiplication.openmp;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	static String MATRIX1 = "matrix1.txt";
	static String MATRIX2 = "matrix2.txt";
	static String RESULT = "result.txt";
		
		public static void readMatrix(ArrayList<ArrayList<Integer>> matrix, String fileFromWhichToRead){
			Scanner input = null;
			try {
				input = new Scanner(new File(fileFromWhichToRead));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}		
			while(input.hasNextLine()) {
			    Scanner rowReader = new Scanner(input.nextLine());
			    ArrayList<Integer> row = new ArrayList<Integer>();
			    while(rowReader.hasNextInt()) {
			        row.add(rowReader.nextInt());		        
			    }
			    matrix.add(row);
			    rowReader.close();
			}
			input.close();
		}
	
	public static void main(String[] args) throws IOException{
		ArrayList<ArrayList<Integer>> matrix1 = new ArrayList<ArrayList<Integer>>();
		ArrayList<ArrayList<Integer>> matrix2 = new ArrayList<ArrayList<Integer>>();
		ArrayDeque<Integer> sharedQueue = new ArrayDeque<>();
			
		readMatrix(matrix1, MATRIX1);
		readMatrix(matrix2, MATRIX2);
		
		ArrayList<ArrayList<Integer>> c = new ArrayList<ArrayList<Integer>>();
		for(int i = 0; i < matrix1.get(0).size(); i++){
			ArrayList<Integer> row = new ArrayList<Integer>();
			for(int j = 0; j < matrix1.get(0).size(); j++){
				row.add(0);
			}
			 c.add(row);
		}
		
		for(int i = 0; i < matrix1.get(0).size() ; i++){
			sharedQueue.add(i);
		}
		
		// omp parallel ThreadNum(4)
		{
			while (!sharedQueue.isEmpty()) {
				
				// omp critical
				int x = sharedQueue.removeFirst();
				
				for(int i = 0; i < matrix2.get(0).size(); i++){
					for(int j = 0; j < matrix1.get(0).size(); j++){
						c.get(x).set(i, c.get(x).get(i) + matrix1.get(x).get(j) * matrix2.get(j).get(i));						
					}
			}
			
			}
		}
		
		Writer result  = new FileWriter(RESULT);
		for(ArrayList<Integer> item: c){
			for(Object item2: item){
				result.write(item2.toString() + " ");
			}
			result.write(" ");
		}
		result.close();
		System.out.print("Done!");
	}

}

