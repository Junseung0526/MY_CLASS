package ch03.practice;

public class Exercise3 {

	public static void main(String[] args) {

		int pencils = 534;
		int students = 30;

		int pencilsPerStudent = pencils / students;
		System.out.println(pencilsPerStudent);

		int pencilsLeft = pencils % students;
		System.out.println(pencilsLeft);
	}

}
