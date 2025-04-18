package ch05.exam;

public class DeskLampEX {

	public static void main(String[] args) {
        DeskLamp l1 = new DeskLamp();
        l1.printStatus();
        System.out.println();

        DeskLamp l2 = new DeskLamp("white");
        l2.printStatus();
        System.out.println();

        DeskLamp l3 = new DeskLamp("white", "deskTop");
        l3.printStatus();
		
	}

}
