bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {

    //percorrer o array até encontrar um 0 e então verificar se os proximos dois tambem são zeros,
    //se sim incrementa Current e continua
    int Current = 0;

    if(flowerbedSize == 1) { //Caso o tamanho for 1
        
        if(flowerbed[0] == 0) {
            Current++;
        }

        if(Current >= n) {
            return true;
        } else {
            return false;
        }
    }

    if(flowerbedSize == 2) { //Caso o tamanho for 2
        
        if(flowerbed[0] == 0 && flowerbed[1] == 0) {
            Current++;
        }

        if(Current >= n) {
            return true;
        } else {
            return false;
        }
    }

    if(flowerbed[0] == 0) {  //Teste inicial
        if(flowerbed[1] == 0) {
            Current++;
            flowerbed[0] == 1;
        }
    }

    for(int i = 1; i < flowerbedSize - 3; i++) {

        if(flowerbed[i] == 0) {
            if(flowerbed[i+1] == 0 && flowerbed[i+2] == 0) {  //runtime error : out of bounds fixed
                Current++;
                flowerbed[i+1] = 1;
            }
        }
    }

    if(flowerbed[flowerbedSize - 1] == 0 && flowerbed[flowerbedSize - 2] == 0) { //teste final
        Current++;
        flowerbed[flowerbedSize - 1] = 1;
    }

    if (Current >= n){
        return true;
    } else {
        return false;
    }


}