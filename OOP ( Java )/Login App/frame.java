import javax.swing.*;
import java.awt.Color;
import java.awt.BorderLayout;

public class frame {
public static void main(String[] args) {
    JFrame f = new JFrame("TITLE");
    f.setSize(400, 100);
	
	JPanel c = new JPanel();
	JButton button = new JButton("Login");
	ImageIcon iconLogo = new ImageIcon("./logo.png");
	JLabel jlImg = new JLabel();
	jlImg.setIcon(iconLogo);
	c.add(button,BorderLayout.CENTER);
	c.add(jlImg,BorderLayout.LINE_END);
	
	JPanel a = new JPanel();
	JLabel lb = new JLabel("Username:");
	JTextField txt = new JTextField("ENTER USERNAME");
	a.add(lb,BorderLayout.PAGE_START);
	a.add(txt,BorderLayout.CENTER);
	
	JPanel b= new JPanel();
	JLabel lb1 = new JLabel("Password:");
	JTextField txt1 = new JTextField("ENTER PASSWORD");
	b.add(lb1,BorderLayout.PAGE_START);
	b.add(txt1,BorderLayout.CENTER);
	
	f.add(a,BorderLayout.PAGE_START);
	f.add(b,BorderLayout.CENTER);
	f.add(c,BorderLayout.PAGE_END);
	
	f.getContentPane().setBackground(Color.gray);
	f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	f.pack();
    f.setVisible(true);
    }
}