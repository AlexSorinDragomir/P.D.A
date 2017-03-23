package matrix.multiplication.without.executor;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.ExecutionException;

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

	public static void main(String args[]) throws InterruptedException, ExecutionException, IOException {
		
		ArrayList<ArrayList<Integer>> matrix1 = new ArrayList<ArrayList<Integer>>();
		ArrayList<ArrayList<Integer>> matrix2 = new ArrayList<ArrayList<Integer>>();
			
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
		
		
		ArrayDeque<Integer> sharedQueue = new ArrayDeque<Integer>();
		
		for(int i = 0; i < matrix1.get(0).size() ; i++){
			sharedQueue.add(i);
		}
		
		MyThread myThread1 = new MyThread(sharedQueue, matrix1, matrix2, c);
		MyThread myThread2 = new MyThread(sharedQueue, matrix1, matrix2, c);
		MyThread myThread3 = new MyThread(sharedQueue, matrix1, matrix2, c);
		MyThread myThread4 = new MyThread(sharedQueue, matrix1, matrix2, c);
		
		myThread1.start();
		myThread2.start();
		myThread3.start();
		myThread4.start();
		
		myThread1.join();
		myThread2.join();
		myThread3.join();
		myThread4.join();
		
		Writer result = new FileWriter(RESULT);
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
