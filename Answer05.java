package ac.uk.napier.set07110Coursework;

import weather.WeatherData;

/**
 * QUESTION 05
 * 
 * If you decide to answer question 05 then the main method below should be used as the entry point for your application
 * You may use as many other classes as you feel necessary as long as all code is supplied 
 * 
 * Remember to add -Xmx1024m to the VM arguments using menu run --> run configurations in eclipse
 */
public class Answer05 {
	public static void main(String[] args) {
		System.out.println("Question 05");
		/*
		 * Add your code below
		 */

		String[] weatherData = WeatherData.getData();		//Make weatherData useful.
		double latitude = 0;								//Store latitude.
		String [] station = new String[100];				//Store location.
		for (int i = 1; i < weatherData.length - 1; i++) 	//Test all data.
		{
			String [] tmpA = weatherData[i].split(",");		//Split data.
			Double hight = Double.parseDouble(tmpA[2]);
			if (hight > latitude)							//Find highest location.
			{
				station = weatherData[i].split(",");
				latitude = hight;
			}
		}
		System.out.println(station[0] + ", " + station[1] + ", " + station[2] + ", " + station [3]);
	}	
}
