ThreadVille
===========

> Raquel Elizondo Barrios  
> Oscar Rodríguez Arroyo  
> Nelson Mendez Montero  
> Carlos Martin Flores Gonzalez  

## Contenidos 
- Construccion
- Ejecucion 
- Comprobación


## Construccion
```bash
$ make

```

## Ejecucion
```bash
$ target/threadville

```

## Usando Docker
```bash
$ sudo docker build -t threadville .
$ sudo docker run -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v $HOME/.Xauthority:/home/developer/.Xauthority --net=host --pid=host --ipc=host threadville
```