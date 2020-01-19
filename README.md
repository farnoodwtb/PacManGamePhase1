# PacManGamePhase1

It is a simple form of PacMan Game in which the computer can plays it itself after pressing 'c' by going for the first'*' until there is none left with a diffrent format for input as 0 is PacMan, 1 is a free house, * is apple and # is a block.
**It also moves with arrow keys as well.**
There is no ghost in this phase but soon it will be upgraded.  **:)**

## Introduction

The PacMan searches the nearest star and goes for it.
For every move it waits 0.5 second.
The program ends with the last star eaten.

### Code Box 

This PRINTF changes color to blue in dev c/c++

````
printf("\033[1;34m");
````
This IF checks if a scroll key was pressed and if not ch will keep whatever is in it.

```
if (ch == 0xE0)
				{
					ch2 = getch();
					switch(ch2)
					{
					case 72: side=8; break;
					case 80: side=2; break;
					case 75: side=4; break;
					case 77: side=6; break;
					default:;
					};
				}
```
These three functions use an array to keep queue and add to it ,remove from it and check if it is empty. 

```
void enqueue(Queue *q,int a)
{
	q->arr[q->j++] = a;
}
int isEmpty(Queue *q)
{
	return q->i >=  q->j;
}
int dequeue(Queue *q)
{
	return q->arr[q->i++];
}
```
 
## Authors

* **ِFarnood**- [farnoodwtb](https://github.com/farnoodwtb)

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/farnoodwtb/PacManGamePhase1/blob/master/LICENSE) file for details
