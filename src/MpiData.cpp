//
//  MpiData.cpp
//
//  Created by Patricio Gonzalez Vivo on 2/19/13.
//
//

#include "MpiData.h"

void MpiData::loadCities( string _cvsFile ){
    
    // Declare a File Stream.
    ifstream fileIn;
	
    // Open your text File:
    fileIn.open( ofToDataPath( _cvsFile ).c_str());
	
    // Check if File is open.
    if(fileIn.is_open()) {
        int lineCount = 0;
        
        while(fileIn != NULL) {
            string temp;
            getline(fileIn, temp);
			
            // Skip empty lines.
            if(temp.length() == 0) {
                //cout << "Skip empty line no: " << lineCount << endl;
            }
            // Skip Comment lines.
            else if(ofToString(temp[0]) == "#") {
                //cout << "Skip Comment line no: " << lineCount << endl;
            } else {
                // Split row into cols.
				// formerly was: vector<string> cols = ofSplitString(rows[lineCount], ",");
                vector<string> values = ofSplitString(temp, ",");
				
                if (lineCount > 0){
                    mpiCity newCity;
                    newCity.nId = ofToInt(values[0]);
                    
                    newCity.name = values[1];
                    newCity.state = values[2];
                    
                    newCity.lat = ofToFloat(values[3]);
                    newCity.lon = ofToFloat(values[4]);
                    int stars = ofToInt(values[5]);
                    
                    switch (stars) {
                        case 1:
                            newCity.category = MPI_CITY_LARGEST_CONCENTRATION;
                            break;
                        case 2:
                            newCity.category = MPI_CITY_FASTEST_GROWING;
                            break;
                        case 3:
                            newCity.category = MPI_CITY_ACTIVE_RECRUITING;
                            break;
                    }
                    
                    newCity.bestPerforming = ofToFloat(values[6]);
                    newCity.wellBeing = ofToFloat(values[7]);
                    
                    cities.push_back(newCity);
                }
                
                lineCount++;
            }
        }
    }
}

void MpiData::loadYear( int _year, string _cvsFile ){

    // Declare a File Stream.
    ifstream fileIn;
	
    // Open your text File:
    fileIn.open( ofToDataPath( _cvsFile ).c_str());
	
    vector<mpiCitySample> newYearSample;
    
    // Check if File is open.
    if(fileIn.is_open()) {
        int lineCount = 0;
        
        while(fileIn != NULL) {
            string temp;
            getline(fileIn, temp);
			
            // Skip empty lines.
            if(temp.length() == 0) {
                //cout << "Skip empty line no: " << lineCount << endl;
            }
            // Skip Comment lines.
            else if(ofToString(temp[0]) == "#") {
                //cout << "Skip Comment line no: " << lineCount << endl;
            } else {
                // Split row into cols.
				// formerly was: vector<string> cols = ofSplitString(rows[lineCount], ",");
                vector<string> values = ofSplitString(temp, ",");
				
                if (lineCount > 0){
                    
                    mpiCitySample newSample;
                    newSample.nId = ofToInt(values[0]);
                    newSample.pop = ofToInt(values[2]);             //  Number: Total pop
                    newSample.popImm = ofToInt(values[3]);          //  Number:  Immigrants
                    newSample.popImmShare = ofToFloat(values[4]);   //  Immigrant share (%) (???)
                    newSample.recArr = ofToFloat(values[5]);        //  Recent arrivals (%) of all immigrants
                    
                    //  Education
                    //
                    newSample.noDegreeImm = ofToFloat(values[6]);    //Percent: No high school degree   Immigrants
                    newSample.hsDegreeImm = ofToFloat(values[7]);    //Percent: High school/AA degree  Immigrants
                    newSample.baDegreeImm = ofToFloat(values[8]);    //Percent: BA/higher  Immigrants
                    newSample.noDegreeNat = ofToFloat(values[9]);   //Percent: No high school degree  Native born
                    newSample.hsDegreeNat = ofToFloat(values[10]);    //Percent: High school/AA degree Native born
                    newSample.baDegreeNat = ofToFloat(values[11]);    //Percent: BA/higher Native born
                    
                    //  Employment
                    //
                    newSample.employedTotal = ofToInt(values[12]);  //Number:  Employed
                    newSample.employedImm = ofToInt(values[13]);    //Number:  Imm  Employed
                    newSample.employedNat = ofToInt(values[14]);    //Number:  Natives  Employed
                    
                    newSample.employedImmShare = ofToFloat(values[15]);   // Imm share among all empl (%) (???)
                    newSample.unEmployment = ofToFloat(values[16]);       //Unemployment rate (%)
                    
                    //  Financial
                    //
                    newSample.poverty = ofToFloat(values[17]);        //Poverty rate (%)
                    newSample.homeOwners = ofToFloat(values[18]);     //Rate of home ownership (%)
                    
                    //  Ethnic/Cultural
                    //
                    newSample.black = ofToFloat(values[19]);          //Percent: Black
                    newSample.asian = ofToFloat(values[20]);          //Percent: Asian
                    newSample.latino = ofToFloat(values[21]);         //Percent: Latino
                    newSample.nonWhite = ofToFloat(values[22]);       //Percent: Non-white
                    newSample.nonEnglSpk = ofToFloat(values[23]);     //Percent: Speak other lang (than English)
                    
                    newSample.creativeClass = ofToFloat(values[24]);
                    
                    //  Job -> education
                    //
                    newSample.noDegreeUnEmployImm = ofToFloat(values[25]);
                    newSample.hsDegreeUnEmployImm = ofToFloat(values[26]);
                    newSample.baDegreeUnEmployImm = ofToFloat(values[27]);
                    newSample.noDegreeUnEmployNat = ofToFloat(values[28]);
                    newSample.hsDegreeUnEmployNat = ofToFloat(values[29]);
                    newSample.baDegreeUnEmployNat = ofToFloat(values[30]);
                    
                    newYearSample.push_back(newSample);
                    
                }
                
                lineCount++;
            }
        }
        
        //  Check between witch years need to be inserted ( sort )
        //
        int offSet = 0;
        for (int i = 0; i < years.size(); i++){
            if ( _year > years[i] )
                offSet = i+1;
        }
        
        years.insert(years.begin()+offSet, _year);
        samples.insert(samples.begin()+offSet,newYearSample);
        
    }
}

float MpiData::getGrowthImmPop(int _cityId,  int _fromYearId, int _toYearId){
    return ( getNumVal( MPI_NUM_IMMIGRANTS, _cityId, _toYearId ) - getNumVal( MPI_NUM_IMMIGRANTS, _cityId, _fromYearId ) )*100/getNumVal( MPI_NUM_IMMIGRANTS, _cityId, _fromYearId );
}

float MpiData::getGrowthNatPop(int _cityId, int _fromYearId, int _toYearId){
    return ( getNumVal( MPI_NUM_NATIVE, _cityId, _toYearId ) - getNumVal( MPI_NUM_NATIVE, _cityId, _fromYearId ) )*100/getNumVal( MPI_NUM_NATIVE, _cityId, _fromYearId );
}

int MpiData::getTotalYears(){
    return years.size();
}

int MpiData::getTotalCities(){
    return cities.size();
}

int MpiData::getTotalSamples(){
    return getTotalYears()*getTotalCities();
}

int MpiData::getYearId( int _year ){
    for (int i = 0; i < years.size(); i++){
        if ( years[i] == _year)
            return i;
    }
    
    return -1;
}

int MpiData::getYear( int _yearId){
    return years[_yearId];
}

vector<int> MpiData::getYears(){
    return years;
}

int MpiData::getFirstYear(){
    return years[0];
}

int MpiData::getLastYear(){
    return years[getTotalYears()-1];
}

int MpiData::getCityId( string _city ){
    for (int i = 0; i < cities.size(); i++){
        if ( cities[i].name == _city)
            return i;
    }
    
    return -1;
}

string MpiData::getCity( int _cityId ){
    if (( _cityId >= 0 ) && (_cityId < cities.size() ))
        return cities[_cityId].name;
    else
        return "FAIL";
}

string MpiData::getState( int _cityId ){
    if (( _cityId >= 0 ) && (_cityId < cities.size() ))
        return cities[_cityId].state;
    else
        return "FAIL";
}

float MpiData::getLatitud( int _cityId ){
    if (( _cityId >= 0 ) && (_cityId < cities.size() ))
        return cities[_cityId].lat;
    else
        return -1;
}

float MpiData::getLongitud( int _cityId ){
    if (( _cityId >= 0 ) && (_cityId < cities.size() ))
        return cities[_cityId].lon;
    else
        return -1;
}

mpiCity MpiData::getCityInfo( int _cityId){
    if (( _cityId >= 0 ) && (_cityId < cities.size() ))
        return cities[_cityId];
    else
        return mpiCity();
}

mpiCityCategory MpiData::getCityCategory( int _cityId ){
    if (( _cityId >= 0 ) && (_cityId < cities.size() ))
        return cities[_cityId].category;
    else
        return mpiCityCategory();
}

float MpiData::getBestPerforming( int _cityId ){
    if (( _cityId >= 0 ) && (_cityId < cities.size() ))
        return cities[_cityId].bestPerforming;
    else
        return -1;
}

float MpiData::getWellBeing(int _cityId){
    if (( _cityId >= 0 ) && (_cityId < cities.size() ))
        return cities[_cityId].wellBeing;
    else
        return -1;
}

vector<mpiCity> MpiData::getCitiesBy( mpiCityCategory _category ){
    vector<mpiCity> rta;
    
    for (int i = 0; i < cities.size(); i++){
        if ( cities[i].category == _category )
            rta.push_back(cities[i]);
    }
    
    return rta;
}

vector<mpiCity> MpiData::getCitiesBy( string _state ){
    vector<mpiCity> rta;
    
    for (int i = 0; i < cities.size(); i++){
        if ( cities[i].state == _state )
            rta.push_back(cities[i]);
    }
    
    return rta;
}

int MpiData::getCityIdMaxVal( mpiNumValue _mpiNumValue , int _yearId){

    if ( _yearId == -1 ){
        
        return getCityIdMaxVal( _mpiNumValue, years.size()-1);
        
    } else {
        float   maxVal = 0;
        int     cityId = -1;
        
        for (int i = 0; i < samples[_yearId].size(); i++){
            int value = samples[_yearId][i].getNumValue(_mpiNumValue);

            if ( value > maxVal ){
                maxVal = value;
                cityId = i;
            }
            
        }
        
        return cityId;
    }
}

int MpiData::getCityIdMinVal( mpiNumValue _mpiNumValue , int _yearId){
    if ( _yearId == -1 ){
        
        return getCityIdMaxVal( _mpiNumValue, years.size()-1);
        
    } else {
        float   minVal = 10000000;
        int     cityId = -1;
        
        for (int i = 0; i < samples[_yearId].size(); i++){
            int value = samples[_yearId][i].getNumValue(_mpiNumValue);
            if ( value < minVal ){
                minVal = value;
                cityId = i;
            }
            
        }
        
        return cityId;
        
    }
}

int MpiData::getCityIdMaxVal( mpiPctValue _mpiPctValue , int _yearId){
    if ( _yearId == -1 ){
        
        return getCityIdMaxVal( _mpiPctValue, years.size()-1);
        
    } else {
        float   maxVal = 0;
        int   cityId = -1;
        
        for (int i = 0; i < samples[_yearId].size(); i++){
            float value = samples[_yearId][i].getPctValue(_mpiPctValue);
            if ( value > maxVal ){
                maxVal = value;
                cityId = i;
            }
        }
        return cityId;
    }
}

int MpiData::getCityIdMinVal( mpiPctValue _mpiPctValue , int _yearId){
    if ( _yearId == -1 ){
        
        return getCityIdMaxVal( _mpiPctValue, years.size()-1);
        
    } else {
        float   minVal = 100;
        int     cityId = -1;
        
        for (int i = 0; i < samples[_yearId].size(); i++){
            float value = samples[_yearId][i].getPctValue(_mpiPctValue);
            if ( value < minVal ){
                minVal = value;
                cityId = i;
            }
            
        }
        
        return cityId;
        
    }
}

float MpiData::getPctVal( mpiPctValue _mpiPctValue, int _cityId , int _yearId ){
    
    //  Can't accept non legal cityId
    //
    if (( _cityId < 0 ) || (_cityId >= cities.size() ))
        return -1;
    
    //  If year not provide let's return the last censed year
    //
    if ( _yearId == -1 ){
        _yearId = years.size()-1;
    } else if (( _yearId < -1 ) || (_yearId >= years.size())){
        return -1;
    }
    
    return  samples[_yearId][_cityId].getPctValue(_mpiPctValue);
}

int MpiData::getNumVal( mpiPctValue _mpiPctValue, int _cityId , int _yearId){
    
    //  Can't accept non legal cityId
    //
    if (( _cityId < 0 ) || (_cityId >= cities.size() ))
        return -1;

    //  If year not provide let's return the last censed year
    //
    if ( _yearId == -1 ){
        _yearId = years.size()-1;
    } else if (( _yearId < -1 ) || (_yearId >= years.size())){
        return -1;
    }
    
    return  samples[_yearId][_cityId].getNumValue(_mpiPctValue);
}

int MpiData::getNumVal( mpiNumValue _mpiNumValue, int _cityId , int _yearId){
    
    //  Can't accept non legal cityId
    //
    if (( _cityId < 0 ) || (_cityId >= cities.size() ))
        return -1;

    //  If year not provide let's return the last censed year
    //
    if ( _yearId == -1 ){
        _yearId = years.size()-1;
    } else if (( _yearId < -1 ) || (_yearId >= years.size())){
        return -1;
    }
    
    return  samples[_yearId][_cityId].getNumValue(_mpiNumValue);
}

float MpiData::getMinPctVal( mpiPctValue _mpiPctValue, int _cityId, int _yearId ){
    
    //  If city ID is not provide search on for the MIN value of all cities
    //
    float minVal = 100;
    
    if ( _cityId == -1 ){
        
        for (int i = 0; i < getTotalCities(); i++ ){
            float val = getMinPctVal( _mpiPctValue, i, _yearId );
            
            if  (val < minVal)
                minVal = val;
        }
        
        return minVal;
    } else {
        
        //  Can't accept non legal cityId
        //
        if (( _cityId < 0 ) || (_cityId >= cities.size() ))
            return -1;
        
        if ( _yearId == -1){
            for (int i = 0; i < years.size(); i++) {
                float val = samples[i][_cityId].getPctValue( _mpiPctValue );
                
                if  (val < minVal)
                    minVal = val;
            }
        } else {
            return samples[_yearId][_cityId].getPctValue( _mpiPctValue );
        }
        
        return minVal;
    }
}

float MpiData::getMaxPctVal( mpiPctValue _mpiPctValue, int _cityId, int _yearId ){
    
    //  If city ID is not provide search on for the MAX value of all cities
    //
    float maxVal = 0;
    
    if ( _cityId == -1 ){
        
        for (int i = 0; i < getTotalCities(); i++ ){
            float val = getMaxPctVal( _mpiPctValue, i, _yearId );
            
            if  (val > maxVal)
                maxVal = val;
        }
        
        return maxVal;
        
    } else {
        
        //  Can't accept non legal cityId
        //
        if (( _cityId < 0 ) || (_cityId >= cities.size() ))
            return -1;
        
        if (_yearId == -1){
            for (int i = 0; i < years.size(); i++) {
                float val = samples[i][_cityId].getPctValue( _mpiPctValue );
                
                if  (val > maxVal)
                    maxVal = val;
            }
        } else {
            return samples[_yearId][_cityId].getPctValue( _mpiPctValue );
        }
        
        return maxVal;
    }
}

int MpiData::getMinNumVal( mpiPctValue _mpiPctValue, int _cityId, int _yearId ){
    //  If city ID is not provide search on for the MIN value of all cities
    //
    int minVal = 100000000;
    
    if ( _cityId == -1 ){
        
        for (int i = 0; i < getTotalCities(); i++ ){
            float val = getMinNumVal( _mpiPctValue, i, _yearId );
            
            if  (val < minVal)
                minVal = val;
        }
        
        return minVal;
    } else {
        
        //  Can't accept non legal cityId
        //
        if (( _cityId < 0 ) || (_cityId >= cities.size() ))
            return -1;
        
        if ( _yearId == -1) {
            for (int i = 0; i < years.size(); i++) {
                int val = samples[i][_cityId].getNumValue( _mpiPctValue );
                
                if  (val < minVal)
                    minVal = val;
            }
        } else {
            return samples[_yearId][_cityId].getNumValue( _mpiPctValue );
        }
        
        return minVal;
    }
}

int MpiData::getMaxNumVal( mpiPctValue _mpiPctValue, int _cityId, int _yearId){
    //  If city ID is not provide search on for the MAX value of all cities
    //
    int maxVal = 0;
    
    if ( _cityId == -1 ){
        
        for (int i = 0; i < getTotalCities(); i++ ){
            int val = getMaxNumVal( _mpiPctValue, i, _yearId );
            
            if  (val > maxVal)
                maxVal = val;
        }
        
        return maxVal;
        
    } else {
        
        //  Can't accept non legal cityId
        //
        if (( _cityId < 0 ) || (_cityId >= cities.size() ))
            return -1;
        
        if ( _yearId == -1) {
            for (int i = 0; i < years.size(); i++) {
                int val = samples[i][_cityId].getNumValue( _mpiPctValue );
                
                if  (val > maxVal)
                    maxVal = val;
            }
        } else {
            return samples[_yearId][_cityId].getNumValue( _mpiPctValue );
        }
        
        return maxVal;
    }
}

int MpiData::getMinNumVal( mpiNumValue _mpiNumValue, int _cityId, int _yearId ){
    //  If city ID is not provide search on for the MIN value of all cities
    //
    int minVal = 100000000;
    
    if ( _cityId == -1 ){
        
        for (int i = 0; i < getTotalCities(); i++ ){
            int val = getMinNumVal( _mpiNumValue, i, _yearId );
            
            if  (val < minVal)
                minVal = val;
        }
        
        return minVal;
    } else {
        
        //  Can't accept non legal cityId
        //
        if (( _cityId < 0 ) || (_cityId >= cities.size() ))
            return -1;
        
        if (_yearId == -1){
            for (int i = 0; i < years.size(); i++) {
                int val = samples[i][_cityId].getNumValue( _mpiNumValue );
                
                if  (val < minVal)
                    minVal = val;
            }
        } else {
            return samples[_yearId][_cityId].getNumValue( _mpiNumValue );
        }
        
        return minVal;
    }
}

int MpiData::getMaxNumVal( mpiNumValue _mpiNumValue, int _cityId, int _yearId ){
    //  If city ID is not provide search on for the MAX value of all cities
    //
    int maxVal = 0;
    
    if ( _cityId == -1 ){
        
        for (int i = 0; i < getTotalCities(); i++ ){
            int val = getMaxNumVal( _mpiNumValue, i, _yearId );
            
            if  (val > maxVal)
                maxVal = val;
        }
        
        return maxVal;
        
    } else {
        
        //  Can't accept non legal cityId
        //
        if (( _cityId < 0 ) || (_cityId >= cities.size() ))
            return -1;
        
        if (_yearId == -1){
            for (int i = 0; i < years.size(); i++) {
                int val = samples[i][_cityId].getNumValue( _mpiNumValue );
                
                if  (val > maxVal)
                    maxVal = val;
            }
        } else {
            return samples[_yearId][_cityId].getNumValue( _mpiNumValue );
        }
        
        return maxVal;
    }
}

mpiCitySample& MpiData::getSample( int _yearId, int _cityId ){
    return samples[_yearId][_cityId];
}

vector<mpiCitySample>& MpiData::getSamples( int _yearId ){
    return samples[_yearId];
}