package ch03.practice;

public class Exercise5 {

	public static void main(String[] args) {

		int lengthTop = 5;
		int lengthBottom = 10;
		int height = 7;
		double area = (lengthTop + lengthBottom) * height / 2.0;
//		(lengthTop + lengthBottom) * height / 
//		(double)(lengthTop + lengthBottom) * height / 2
		System.out.println(area);
	}

}
