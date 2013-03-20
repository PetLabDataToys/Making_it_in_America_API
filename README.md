# Making it in America: *The Immigrant Success Index*###### a [PETlab](http://petlab.parsons.edu/) project with [PRI](http://www.pri.org/) and the [Migration Policy Institute](http://www.migrationpolicy.org/) January 2013
## The Big IdeaImmigrants have been the engine of growth for the US since its founding as a nation. But that engine may be stalling after years of bitter debate over how to treat immigrants.The Immigrant Success Index aims to add hard facts and aha’s to the public debate about immigrants and immigration reform. Today’s debate and media coverage frames issues as “us” versus “them”, as legal versus illegal, and as faceless people versus neighbors, friends and colleagues. The political climate is opening now for a richer discussion and we want to enrich the debate. We plan to do that by telling personal stories about immigrant life here and uncovering the cities where immigrants are more likely to succeed and what policies, services and factors help or hurt them.## The Partners
* **[Public Radio International (PRI)](http://www.pri.org/)** is the second leading distributor of public radio shows after NPR. We produce and/or distribute shows like This American Life, The World, Afropop, Studio360 and Tavis Smiley. Our mission is to give people the information, insights and cultural experiences they need to live in a diverse, interconnected world. And we have a major initiative to reach and engage immigrants in the US to bring their voices into public debate, provide unbiased stories of their role and experiences in our society, and get all Americans involved in Siguring out our approach to immigrants and immigration. PRI is creating the Index as a way to help local journalists and citizens tell true stories about immigrant life in America as well as city policy makers who are interested in attracting and engaging their immigrant populations.* **[The Migration Policy Institute (MPI)](http://www.migrationpolicy.org/)** is an independent, nonpartisan, nonproSit think tank in Washington, DC dedicated to analyzing the movement of people worldwide. It believes that sound immigration and integration policies result from balanced analysis, solid data, and the engagement of a spectrum of stakeholders — from community leaders and immigrant organizations to the policy elite — interested in immigration policy and its human consequences. MPI is gathering the data and providing the analytic smarts to ensure the Immigrant Success Index is as accurate, honest and revealing as possible.
## The DataBase 
The dataBase consist on 3 samples made between 2000,2005 and 2010 over the following 25 cities (selected out of the 100 most populous cities in the United States)![cities](https://raw.github.com/patriciogonzalezvivo/DataToys/master/Making_it_in_America/images/cities.png)
	Baltimore, MD +++		Boise City, ID +++	
	Boulder, CO +++ 		Charlotte, SC ++
	Columbus, OH ++ 		Dayton, OH +++
	Washington DC + 		Indianapolis, IN++
	Los Angeles, CA + 		Miami, FL+
	New York, NY + 			Richmond, VA ++	
	San Francisco, CA +		Birmingham, AL ++ 
	Boston, MA +			Cape Coral, FL ++ 
	Chicago, IL + 			Dallas, TX + 
	Detroit, MI +++ 		Houston, TX + 
	Lakeland, FL ++ 		Louisville, KY ++ 
	Nashville, TN ++ 		Raleigh, NC ++ 
	Riverside, CA +

Reference:

	+   Ten cities with largest concentration of foreign-born population 
	++  Ten cities with fastest growing foreign-born population 
	+++ Five cities most actively recruiting the foreign born
	
	
Over this cities in each of the three years (2000, 2005, and 2010) you will see: 

* Number: Total population* Number of immigrants* Immigrant share (%)* % immigrants who are recent arrivals (arrived within the last 10 years)* Among immigrant adults (pop. 25+): % low-, middle-, and high skilled* Among native adults (pop. 25+): % low-, middle-, and high skilled* Number of all employed workers (pop. 16+)* Number of immigrant employed workers (pop. 16+)* Number of native employed workers (pop. 16+)* Immigrant share (% among all employed)* % Unemployed (of total pop.)* % in Poverty (of total pop.)* % Speakers of languages other than English, % Black, % Asian, % Latino, and % who are non-whites (of total pop.) (these serve as proxies for ethnic/linguistic diversity)* % ‘Creative class’ (i.e., share employed in professional occupations and had at least a bachelor’s degree among all employed adults) For more on the creative class, see Richard Florida who argued that there is a strong connection between a large-scale presence of the creative class of workers – people who work in science and technology; business and management; arts, culture and
entertainment; medicine and education – and the prosperity of cities. [More information](http:// www.washingtonmonthly.com/features/2001/0205.florida.html) * Best-Performing Cities Index (the Milken Institute index, 2010) The Best-Performing Cities index ranks US metropolitan areas by how well they are creating and sustaining jobs and economic growth. The components include job, wage and salary, and technology growth. In most years, these give a good indication of the underlying structural performance of regional economics. [More information](http://bestcities.milkeninstitute.org/bestcities2012.taf?rankyear=2010&type=rank200)* City Well-Being Index (the Gallup Poll index, 2010) The Gallup-Healthways Well-Being Index score is an average of six sub-indexes, which individually examine life evaluation, emotional health, work environment, physical health, healthy behaviors, and access to basic necessities. The overall score and each of the six sub-index scores are calculated on a scale from 0 to 100, where a score of 100 represents the ideal. In 2010, the national average score was 66.8. [More information](http://www.gallup.com/poll/145913/City-Wellbeing-Tracking.aspx)

## Preparation of the dataBased
[The data base received](https://docs.google.com/file/d/0B9yD5YLwxGTIck8zUS1adGRuVEk/edit?usp=sharing) was a MS Excel document with a big table with the three years census one next to the other. In order to work and process the data it was necessary to:

*	Transform the dataBase from an MS Excel file into a [Google Spreadsheet one](https://docs.google.com/spreadsheet/ccc?key=0AsKqVj4h_cOwdDlTMGRfMGtxOFFrY0gxc1lZdGZFbFE&usp=sharing)
*	Match the name of the Cities and States according to the [project_overview.pdf](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/doc/project_overview.pdf?raw=true)
*	Separate the cities in a different table ( [```cities.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/cities.csv) ) and replace it by IDs. This separation makes the information of the city independent of the three samples
*	Research the geographical location of the cities (Lat & Long)
*	Add the selection criteria of each city
*	Split the samples according to the three years and export them as CSV (comma separated values) files: [```2000.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/2000.csv), [```2005.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/2005.csv) and [```2010.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/2010.csv) 
	
## The DataBase and the openSource C++ API for openFrameworks

### Installing the MPI Data Base

This tools are wrote on openFrameworks. So we first need to install openFrameworks and then adding this libraries to it:

1. The first thing to do is [download and install openFrameworks](http://www.openframeworks.cc/download/)

2. After that download this repo clicking on the download buttom:
![github](https://raw.github.com/patriciogonzalezvivo/DataToys/master/Making_it_in_America/images/github.png)

3. Unzip the folder an place it on your ```apps``` folder.

![github](https://raw.github.com/patriciogonzalezvivo/DataToys/master/Making_it_in_America/images/apps.png)

From that you can compile and see the project examples.

If you are interested on making your own project you need:

1. You need to copy the [.csv files](https://github.com/patriciogonzalezvivo/DataToys/tree/master/Making_it_in_America/data) ( [```cities.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/cities.csv), [```2000.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/2000.csv), [```2005.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/2005.csv) and [```2010.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/2010.csv)) to the ```bin/data``` folder on your openFrameworks project.

2. Then you also need to copy the [```.h``` and ```.cpp``` files in the src folder](https://github.com/patriciogonzalezvivo/DataToys/tree/master/Making_it_in_America/src) ( [```MpiElements.h```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/src/MpiElements.h), [```MpiData.h```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/src/MpiData.h) and [```MpiData.cpp```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/src/MpiData.cpp) ) to your ```src/``` folder on your openFrameworks project. 

3. In order to use the dataBase you need to declare a ```MpiData``` object on your ```testApp.h``` together with the ```#include ``` call to the [```MpiData.h```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/src/MpiData.h) header file.

That should look like:

	#pragma once

	#include "ofMain.h"
	#include "MpiData.h"

	class testApp : public ofBaseApp{
	public:
    	void setup();
    	void update();
    	void draw();

    	void keyPressed  (int key);
    	void keyReleased(int key);
    	void mouseMoved(int x, int y );
    	void mouseDragged(int x, int y, int button);
    	void mousePressed(int x, int y, int button);
    	void mouseReleased(int x, int y, int button);
    	void windowResized(int w, int h);
    	void dragEvent(ofDragInfo dragInfo);
    	void gotMessage(ofMessage msg);
    
    	MpiData     dBase;
 
	};
  
After doing this you are ready to load and use the data base.

### Elements
The elements that are going to be use for the API are defined at [```MpiElements.h```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/src/MpiElements.h) and it's composed by: 

* ```mpiCity```: this object contain the information of the chosen cities and is populated with the [```cities.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/cities.csv). The object contain the following variables

		int     nId;   		//	This is used to cross the information between tables		
    	string  name;       //  Name of the City. Ex: "New York"
    	string  state;      //  To capital letters that describe the State. i.e. "NY"
    
    	float   lat;    	//  Lat geo position of the city: i.e. 43.00
    	float   lon;   		//  Long geo position of the city: i.e. -75.00
    
    	float   bestPerforming;     // Best Performing Citie Index
    	float   wellBeing;  //  Well-Being Citie Index (National Avergge 66.8)
    	
    	mpiCityCategory category;	//	Selected City criteria

	
* ```mpiCityCategory```: this variable contain the three different criterial category already described. This variable could be one of the following values 

		MPI_CITY_LARGEST_CONCENTRATION  //  10 cities with largest concentration of foreing-born pop
		MPI_CITY_FASTEST_GROWING        //  10 cities with fastest growing foreing-born pop
		MPI_CITY_ACTIVE_RECRUITING       //  5 cities most actively cruiting the foreing born

* ```mpiNumValue```: the tables [```2000.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/2000.csv), [```2005.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/2005.csv) and [```2010.csv```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/data/2010.csv) contain integer information of population together with percentages. ```mpiNumValue``` is a variable type that referee to those integers one that hold total amount of persons. As you can see the last three values are based on people over 16+ years old. This variable could be one of the following values 

		MPI_NUM_POPULATION
		MPI_NUM_IMMIGRANTS
		MPI_NUM_EMPLOYED               //  (pop. 16+)
		MPI_NUM_EMPLOYED_IMMIGRANTS    //  (pop. 16+)
		MPI_NUM_EMPLOYED_NATIVE        //  (pop. 16+)


* ```mpiPctValue```: referee to those values that are percentages of different populations.   This one could be:

	    MPI_PCT_POPULATION_SHARE
	    MPI_PCT_RECENT_ARRIVALS
	    
    	MPI_PCT_DEGREE_IMMIGRANTS_NO,           //  (pop. 25+)
    	MPI_PCT_DEGREE_IMMIGRANTS_HIGHSCHOOL,   //  (pop. 25+)
    	MPI_PCT_DEGREE_IMMIGRANTS_BA,           //  (pop. 25+)
    	MPI_PCT_DEGREE_NATIVE_NO,               //  (pop. 25+)
    	MPI_PCT_DEGREE_NATIVE_HIGHSCHOOL,       //  (pop. 25+)
    	MPI_PCT_DEGREE_NATIVE_BA,               //  (pop. 25+)

    	MPI_PCT_EMPLOYED_SHARE,
    	MPI_PCT_UNEMPLOYMENT,
    	MPI_PCT_POVERTY,
    	MPI_PCT_HOMEOWNERS,

    	MPI_PCT_ETHNIC_BLACK,
    	MPI_PCT_ETHNIC_ASIAN,
    	MPI_PCT_ETHNIC_LATINO,
    	MPI_PCT_ETHNIC_NONWHITE,
    	MPI_PCT_ETHNIC_NONENGLISH_SPK,

    	MPI_PCT_CREATIVE_CLASS

For a more information about this values please read this [overview of the data](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/doc/data_overview.pdf?raw=true)


* ```mpiCitySample```: this is the object that holds all the data from each city in a particular year. Beside the variables that holds this information is important to know that there are three functions that let you request and transform values:

		int     nId;
    
		int     getNumValue( mpiNumValue _numValue ) // return TOTAL NUMBERS 
		float   getPctValue( mpiPctValue _pctValue ) // return PERCENTAGES (PCT)
    	int 	getNumValue( mpiPctValue _pctValue ) // transform from PCT to TOTAL NUMBER 
        
It's important to know that if you are getting a ```-1``` it's because the information can't be provided. For example if you want to get the TOTAL NUMBER of immigrant with no deegree it can't be done. Looking above you will see that's because that percentage it of the population over 25+ witch we don't have. Those 6 options with the same characteristic are the only one that can be satisfy correctly. 

### DataBase Motor 

* [```MpiData```](https://github.com/patriciogonzalezvivo/DataToys/blob/master/Making_it_in_America/src/MpiData.h): This object represent the core of this API. It's an C++ object ready for loading the .csv and process it information. Once this files are loads you can make request asking for specific information. The methods are


		//		Loading of the information
		//
		void    loadCities( string _cvsFile );
		void    loadYear( int _year, string _cvsFile );
    
    	//      YEAR
    	//
    	int     getTotalYears();
    	int     getYearId( int _year );
    	int     getYear( int _yearId);
    	vector<int> getYears();
    	int     getFirstYear();
    	int     getLastYear();
    
    	//      CITY
    	//
    	int     getTotalCities();           // return the total number of cities
    	int     getCityId( string _city );  // giving a city name it return the ID
    	string  getCity( int _cityId );     // return the name of the city
    	string  getState( int _cityId );    // return the state of a city
    	float   getLatitud( int _cityId );  // return the lat
    	float   getLongitud( int _cityId ); // return the longitud
    	float   getBestPerforming( int _cityId );
    	float   getWellBeing(int _cityId);
    	mpiCityCategory getCityCategory( int _cityId); //return the city category
    
    	mpiCity getCityInfo( int _cityId );  // giving a city ID return a mpiCity
    	vector<mpiCity> getCitiesBy( mpiCityCategory _category );     		vector<mpiCity> getCitiesBy( string _state ); 
    	    
    	//      VALUES
    	//
    	float   getPctVal( mpiPctValue _mpiPctValue, int _cityId , int _yearId = -1);       		int     getNumVal( mpiPctValue _mpiPctValue, int _cityId , int _yearId = -1);    		int     getNumVal( mpiNumValue _mpiNumValue, int _cityId , int _yearId = -1);
    	        
    	float   getMinPctVal( mpiPctValue _mpiNumValue, int _cityId = -1);
    	float   getMaxPctVal( mpiPctValue _mpiNumValue, int _cityId = -1);
    	int     getMinNumVal( mpiPctValue _mpiNumValue, int _cityId = -1);
    	int     getMaxNumVal( mpiPctValue _mpiNumValue, int _cityId = -1);
    	int     getMinNumVal( mpiNumValue _mpiNumValue, int _cityId = -1);
    	int     getMaxNumVal( mpiNumValue _mpiNumValue, int _cityId = -1);
    
    	int     getCityIdMaxVal( mpiNumValue _mpiNumValue , int _yearId = -1);      		int     getCityIdMinVal( mpiNumValue _mpiNumValue , int _yearId = -1);
    	int     getCityIdMaxVal( mpiPctValue _mpiPctValue , int _yearId = -1);
    	int     getCityIdMinVal( mpiPctValue _mpiPctValue , int _yearId = -1);
    	    
    	//      SAMPLES
    	//
    	int                     getTotalSamples();
    	vector<mpiCitySample>&  getSamples( int _yearId );
    	mpiCitySample&          getSample( int _yearId, int _cityId );
    
It's important to note that in order to make a proper request you need to provide ID's numbers of cities or years. That means that first you need to request the ID of the city or the year you want to get. 

If you look to the method to request values you will see that is difference between asking for a total number (```…Num…```)rather dan a percentage (```…Pct…```). In the first case you get an integer number (```int```) with the total amount of people and in the second case you receive a floating point (```float```) percentage of the population. There is a third case where you can ask for a total number of a percentage. I.E.

	int     getNumVal( mpiPctValue _mpiNumValue, int _cityId , int _yearId = -1);
	
That could be:

	int		unEmploy = dBase.getNumVal( MPI_PCT_UNEMPLOYMENT );

In this case the number is converted from percentage to total numbers. ( ***Note:*** *that you can not do this with the six percentages related to education because they are based just on the population over 25+*

Other important thing to realize of this example is the absence of the year ID. In this particular case means that if the year is not provided it will return the value of the last register year. Also when you are asking for maximum and minimum values you don't need to specify the city. In those cases it will search for all the max and min values on all the years and all the cities of the dataBase

### Using the MPI Data Base
First you need to load the .csv files

    	dBase.loadCities( "cities.csv");
    	dBase.loadYear(2000, "2000.csv");
    	dBase.loadYear(2010, "2010.csv");
    	dBase.loadYear(2005, "2005.csv");

After doing that you can start making request like for example:

*	Asking for the first and last registered years on the data base

		cout << "The first year is: " << dBase.getFirstYear() << endl;
		cout << "The last year is: " << dBase.getLastYear() << endl;
    
*	Asking for the total population of Boston

		cout << "The population of Boston on 2010 was " << dBase.getNumVal(MPI_NUM_POPULATION, dBase.getCityId("Boston"), dBase.getYearId(2010)) << endl;
    
    
* Conversions between percentages and total amount of peopel

		cout << "The percentage of the creative class in Miami is %" << dBase.getPctVal(MPI_PCT_CREATIVE_CLASS, dBase.getCityId("Miami") ) << endl;
    	cout << "Witch means the total of " << dBase.getNumVal(MPI_PCT_CREATIVE_CLASS, dBase.getCityId("Miami") ) << " individuals" << endl;
    
* Request for list of cities

		vector<mpiCity> activeCities;
    	activeCities = dBase.getCitiesBy(MPI_CITY_ACTIVE_RECRUITING);
    	cout << "The cities that actively recruit more are: ";
    	for (int i = 0; i < activeCities.size(); i++) {
        	cout << activeCities[i].name << ", ";
    	}
    	cout << endl;
    
* search for cities with maximum or minimum values 

		cout << "The city with highiest number of immigrants is " << dBase.getCity( dBase.getCityIdMaxVal(MPI_NUM_IMMIGRANTS ) ) << endl;
    	cout << "The city with highiest unemployment percent is " << dBase.getCity( dBase.getCityIdMaxVal(MPI_PCT_UNEMPLOYMENT) ) << endl;
 

### Examples
For exploring more features and possibilities take a look to following examples 

#### DataVisualizer Basic
This is a simple example how to use the data-base by making simple searches, charts and city requests. Together with this example you will found another project compiled to iPhone. This is a great place to start knowing a little better about the data-base and brain storming some ideas of what to do with it.

![chart](https://raw.github.com/patriciogonzalezvivo/DataToys/master/Making_it_in_America/images/chart.png)

#### DataVisualizer Comp
This is a little more complex example that gives you an idea to how compear and explore on the database for patterns by making comparisons.

![chart_comp](https://raw.github.com/patriciogonzalezvivo/DataToys/master/Making_it_in_America/images/comp.png)

#### GeoDataLocator Basic
This is another super simple example of how to put data on the map. This map is using [ModestMap API](http://modestmaps.com/) thanks to [Tom Carden project for OF](https://github.com/RandomEtc/modestmaps-of) how mades a oF wrapper that load the content from the web. It's just like google maps. This is just a starting for start thinking and prototyping awesome ideas. 

![cities](https://raw.github.com/patriciogonzalezvivo/DataToys/master/Making_it_in_America/images/cities.png)

#### GeoDataLocator Comp
A little more complex project that use the [ModestMap](http://modestmaps.com/) is this one where you can search and compare values of our dataBase by pointing in one direction inside the map. The idea is this could be on your phone an by knowing where are you and in what direction are you pointing show you different information
![map](https://raw.github.com/patriciogonzalezvivo/DataToys/master/Making_it_in_America/images/map.png)

#### WDB 3D map
This is essentially the same thing than the last two examples but on 3D. It's using an [CIA World DataBank](http://www.evl.uic.edu/pape/data/WDB/) witch is very big and precise. It takes time to load all those point but the result looks just like Tron and WarGames at the same time.
![map](https://raw.github.com/patriciogonzalezvivo/DataToys/master/Making_it_in_America/images/WDB.png)
