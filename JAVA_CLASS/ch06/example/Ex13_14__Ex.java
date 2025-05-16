package ch06.example;

public class Ex13_14__Ex {

	public class Member {
		String name;
		String id;
		String password;
		int age;

		Member(String name, String id) {
			this.name = name;
			this.id = id;
		}
	}

	public static void main(String[] args) {
		Ex13_14__Ex outer = new Ex13_14__Ex();
		Member user1 = outer.new Member("honggildong", "Hong");
	}
}
