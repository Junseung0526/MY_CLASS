package ch05.exam;

public class DeskLamp {
	
	boolean isOn = true;
	String color;
	String kind; 	

	public DeskLamp() {
		
	}
	
	public DeskLamp(String color) {
		this.color = color;
	}
	
	public DeskLamp(String color, String kind) {
		this.color = color;
		this.kind = kind;
	}
	
	public void printStatus() {
		System.out.println("On/Off Status: " + isOn);
		System.out.println("Color: " + color);
		if(kind != null) {
			System.out.println("Kind: " + kind);
		}
	}
	public static void main(String[] args) {
		DeskLamp l1 = new DeskLamp();
		l1.printStatus();
		System.out.println();
		
		DeskLamp l2 = new DeskLamp("White");
		l2.printStatus();
		System.out.println();
		
		DeskLamp l3 = new DeskLamp("White","DeskTop");
		l3.printStatus();
	}

}
