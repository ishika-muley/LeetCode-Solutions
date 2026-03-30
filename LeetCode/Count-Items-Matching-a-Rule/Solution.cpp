    int count=0;
    for(int i=0;i<items.size();i++){
        List <String> currentList = items.get(i);
        if(ruleKey=="type"&&ruleValue.equals(currentList.get(0))){
            count++;
        }
        else if(ruleKey=="color"&&ruleValue.equals(currentList.get(1))){
            count++;
        }
        else if(ruleKey=="name"&&ruleValue.equals(currentList.get(2))){
            count++;
        }
    }
    return count;
}