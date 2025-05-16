package ch06.example;

public class MemberServiceEx {

	public static void main(String[] args) {
		MemberService mc = new MemberService();
		boolean result = mc.login("hong", "12345");
		if (result) {
			System.out.println("로그인 되었습니다.");
			mc.logout("hong");
		}else {
			System.out.println("id 또는 password가 올바르지 않습니다.");
		}
	}

}
