double maxVolume(double p, double a) {
        double l=(p-(sqrt(pow(p,2)-24*a)))/12;
        double maxv=(p*pow(l,2)-8*pow(l,3))/4;
        return maxv;
    }
