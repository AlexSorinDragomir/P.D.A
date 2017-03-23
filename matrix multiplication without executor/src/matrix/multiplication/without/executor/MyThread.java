package matrix.multiplication.without.executor;

import java.util.ArrayDeque;
import java.util.ArrayList;

public class MyThread extends Thread {
	private ArrayDeque<Integer> sharedQueue;
	ArrayList<ArrayList<Integer>> matrix1;
	ArrayList<ArrayList<Integer>> matrix2;
	ArrayList<ArrayList<Integer>> result;
	int x = 0;

	public MyThread(ArrayDeque<Integer> sharedQueue, ArrayList<ArrayList<Integer>> matrix1, ArrayList<ArrayList<Integer>> matrix2, ArrayList<ArrayList<Integer>> result) {
        this.sharedQueue = sharedQueue;
        this.matrix1 = matrix1;
		this.matrix2 = matrix2;
		this.result = result;
    }
	
	
	@Override
    public void run() {
       
			while (!sharedQueue.isEmpty()) {
				
				synchronized(sharedQueue){
					x = sharedQueue.removeFirst();
				}
				
				for(int i = 0; i < matrix2.get(0).size(); i++){
					for(int j = 0; j < matrix1.get(0).size(); j++){
						result.get(x).set(i, result.get(x).get(i) + matrix1.get(x).get(j) * matrix2.get(j).get(i));						
					}
				}

			}
	}
}
