package ac.uk.napier.set07110Coursework;

import java.util.HashSet;

import weather.WeatherData;

/**
 * QUESTION 04
 * 
 * If you decide to answer question 04 then the main method below should be used as the entry point for your application
 * You may use as many other classes as you feel necessary as long as all code is supplied 
 * 
 * Remember to add -Xmx1024m to the VM arguments using menu run --> run configurations in eclipse
 */
public class Answer04 {
	public static void main(String[] args) {
		System.out.println("Question 04");
		/*
		 * Add your code below
		 */

		String[] weatherData = WeatherData.getData();		//Make weatherData useful.
		HashSet<String> date = new HashSet<String>();		//Store date.
		int i = 1;
		String day;
		String month;
		String fullDate;

		while (i < weatherData.length - 1) {				//Test all data.
			String [] tmpA = weatherData[i].split(",");		//Split data.
			if (Double.parseDouble(tmpA[9]) <= -2.0){		//Check temperature.
				day = (tmpA[6]);
				month = (tmpA[5]);
				fullDate = day + "-" + month;				//Create full dates.
				date.add(fullDate);
				i++;
			}
			else {
				i++;
			}
		}
		System.out.println("It was -2 or below " + date.size() + " days.");
	}
}
