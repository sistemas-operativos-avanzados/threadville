
Y1 y = new Y1(); //En Y1 nacen los carros
Threadville T = new Threadville(Y1, Z1, .....);
T.addCar();

// T.addTruck();
// T.addBus();

// en Y


function isAllowed(){
    return y1.isBusy();
}

function Car newCar(){

    if(this.isAllowed() == true){ 
        Route route = RouteGenerator.randomRoute();      // [G5]
        ColorAndSpeed cs = ColorAndSpeedGenerator.new(); // RED: 1s 
        Car car = new Car(route, cs);
        return car;
    }

    return null;
}


// en Threadville
Y

function addCar(){
    Car car = Y.newCar();
    car.go();
}

// en Car

Route[] route //[G5]

function void go(){

    jumps = howTo(Y1, G5) 
    [Y1, Y6, Y5, Y4, Y3, Y2, G5]
    [G5]

    next(jumps[1], jumps - 1, car)
        Y1, [Y6, Y5, Y4, Y3, G5], car
}

function void next(Next next, Jumps jumps, Car car){
    if (next.processCar(car)){ //true | false
        next(jumps[1], jumps - 1, car);
    }
}

