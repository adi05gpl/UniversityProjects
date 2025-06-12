import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Date;
import java.io.*;
import java.text.SimpleDateFormat;

public class ExSingleton{
		private static ExSingleton _inst=null;
		public static ExSingleton getInst(){
			if(null == _inst){
				_inst=new ExSingleton();
			}
			return _inst;
		}
}

