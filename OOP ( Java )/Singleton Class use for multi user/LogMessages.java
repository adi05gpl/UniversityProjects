import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Date;
import java.io.*;
import java.text.SimpleDateFormat;

public class LogMessages{
	
	private BufferedWriter _bw;
	public void initialize(String fName){
		try{
			if(null != _bw) throw new Exception("initialize");
			File f = new File("logf.txt");
			if (!f.exists()) { f.createNewFile(); }
			FileWriter fw = new FileWriter(f.getAbsoluteFile());
			_bw = new BufferedWriter(fw);
			_bw.write("FELICITARI");
			_bw.close();
			}catch(Exception ex){}
	}
	
	public void logMessage(String msg){
		if(null == _bw) return;
		String timeStamp = new SimpleDateFormat("yyyy.MM.dd HH.mm.ss").format(new Date());
		StringBuffer out = new StringBuffer(timeStamp);
		out.append(msg);
		try{
			_bw.write(msg);
			_bw.flush();
		}catch(Exception ex){}
	}
	public void close(){
		if(null == _bw) return;
		try{
			_bw.close();
		}catch(Exception ex){}
		_bw=null;
	}
}