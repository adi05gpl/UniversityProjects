import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Date;
import java.io.*;
import java.text.SimpleDateFormat;

class Lab3 {

	public static void main(String[] args){
		MyFrame mf = new MyFrame("TREABA");
		mf.createFrame();
		Persoana pe = new Persoana("Adrian", "ihbhjb");
		LogMessages lm = new LogMessages();
		lm.initialize("aaa");
		lm.logMessage("text reusit");
		
	}
}