package ac.uk.napier.set07110Coursework;

import weather.WeatherData;

/**
 * QUESTION 03
 * 
 * If you decide to answer question 03 then the main method below should be used as the entry point for your application
 * You may use as many other classes as you feel necessary as long as all code is supplied 
 * 
 * Remember to add -Xmx1024m to the VM arguments using menu run --> run configurations in eclipse
 */
public class Answer03 {
	public static void main(String[] args) {
		System.out.println("Question 03");
		/*
		 * Add your code below
		 */
		
		String[] weatherData = WeatherData.getData();

		int index = 1;
		int total = 0;
		double min = 1000;
		double max = 0;
		double mean = 0;
	
		for (index = 1; index < weatherData.length - 1; index++) 
		{
			
		String [] tmpA = weatherData[index].split(",");
			
			if ( tmpA[7].equals("6") && tmpA[5].equals("1") && tmpA[0].equals("3768")) {
				double temp = Double.parseDouble(tmpA[9]);
				mean = mean + temp;
				total++;
			
				if (temp < min) {
					min = temp;
				}
			
				else if (temp > max) {
					max =temp;
				}

		}
	}
			
		mean = mean / 2;
		
		System.out.println("Min=" + min + " Max=" + max + " Mean=" + mean + " There are " 
		+ total + " entries for Weather station 3768 at 6 AM during January 2015");
	}
}
