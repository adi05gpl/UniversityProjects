import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Date;
import java.io.*;
import java.text.SimpleDateFormat;


public class MyFrame implements ActionListener {
	private String _titlu;
	private JTextField u;
	private JTextField p;


	public MyFrame(String titlu){
		_titlu = titlu;
	}
	public void createFrame(){
		JFrame f=new JFrame(_titlu);
		JPanel j=new JPanel();
		JPanel i=new JPanel();
		
		JLabel lb=new JLabel("Username: ");
		j.add(lb,BorderLayout.PAGE_START);
		u=new JTextField("Username");
		j.add(u);
		i.add(j);
		
		JLabel lc=new JLabel("Password:");
		i.add(lc,BorderLayout.CENTER);
		p=new JTextField("Password");
		i.add(p);
		f.add(i);
		
		ImageIcon iconLogo=new ImageIcon("./img.png");
		JPanel img=new JPanel();
		JLabel jll = new JLabel();
		jll.setIcon(iconLogo);
		img.add(jll,BorderLayout.LINE_END);
		
		JButton ld=new JButton("LOGIN");
		ld.addActionListener(this);
		img.add(ld);
		f.add(img,BorderLayout.PAGE_END);
		f.getContentPane().setBackground(Color.WHITE);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.pack();
		f.setVisible(true);
	}
	public void actionPerformed(ActionEvent event){
		int a=JOptionPane.showConfirmDialog(null, "Are you sure you want to login?", "Question",
		JOptionPane.YES_NO_CANCEL_OPTION,JOptionPane.QUESTION_MESSAGE);
		
		if(a==JOptionPane.YES_OPTION){
		JOptionPane.showMessageDialog(null,
		"You have selected to login!", "Result", JOptionPane.INFORMATION_MESSAGE);	
			System.out.println(HelperChecksum.computeCkSum1(u.getText()));
			System.out.println(HelperChecksum.computeCkSum2(p.getText()));

		}else if(a==JOptionPane.NO_OPTION){
		JOptionPane.showMessageDialog(null,"You have selected not to login!","Result",JOptionPane.WARNING_MESSAGE);
		}
		else if(a==JOptionPane.CANCEL_OPTION){
		JOptionPane.showMessageDialog(null,"You pressed cancel !!","Result",JOptionPane.ERROR_MESSAGE);
		}
	}
}