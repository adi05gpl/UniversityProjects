import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class MyFrame implements ActionListener {
	private String _titlu;



	public MyFrame(String titlu){
		_titlu = titlu;
	}
	public void createFrame(){
		JFrame f=new JFrame(_titlu);
		JPanel j=new JPanel();
		JPanel i=new JPanel();
		
		JLabel lb=new JLabel("Username: ");
		j.add(lb,BorderLayout.PAGE_START);
		JTextField u=new JTextField("Username");
		j.add(u);
		i.add(j);
		
		JLabel lc=new JLabel("Password:");
		i.add(lc,BorderLayout.CENTER);
		JTextField p=new JTextField("Password");
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
		int a = JOptionPane.showConfirmDialog(null,"Did you read my book?",
        "Art of War",JOptionPane.YES_NO_CANCEL_OPTION,
        JOptionPane.QUESTION_MESSAGE);
		if(a==JOptionPane.YES_OPTION){
		JOptionPane.showConfirmDialog(null,
		"Will you tell me what you liked about it?", "Interactions", JOptionPane.YES_NO_OPTION);
		String inputValue = JOptionPane.showInputDialog("Please input your comment !",JOptionPane.YES_OPTION);

		}else if(a==JOptionPane.NO_OPTION)
		JOptionPane.showConfirmDialog(null,
		"I hope you will !", "Interactions", JOptionPane.ERROR_OPTION);
	}
}