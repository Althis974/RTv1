# RTv1

## Introduction

  Pour une fois, le sujet est en rapport avec le préambule. Pour réussir, vous devez échouer. C’est pour cela que vous allez commencer par une sorte de proof-of-concept du principe du Raytracing. C’est l’objet du RTv1 : vous familiariser avec le lancer de rayon,les élements géometriques à manipuler, la description de la scène...
  Vous allez donc réussir, ou échouer, ce projet dans le but de le faire par la suite plus gros, plus grand, plus bôôôooo, avec tout plein d’options (ça sera le RT tout court - ne commencez donc pas le RT sans avoir fait le RTv1, c’est pas raisonnable).

  Voyez la vidéo avec la démo pour comprendre ce que l’on a au départ, et ce que doit faire votre programme. Les ressources sur le net sont plutôt importantes en matière d’explication du Raytracing. Les approches sont parfois variées, trouvez celle qui vous convient. Le RTv1 reste une version simple, voyez ce qui est demandé pour ne pas vous perdre dans des méandres des très nombreuses fonctionnalités que peut contenir un tel programme et qu’il vous faut de toute façon conserver pour le RT.
  
## Objectifs
  
  Quand il s’agit de générer des images de synthèse en 3 dimensions, il existe en gros deux approches : la “Rasterisation”, qui est le procédé utilisé par l’écrasante majorité des moteurs de rendus pour son efficacité, et le “Ray Tracing”, approche beaucoup plus lourde en terme de calculs, donc peu adapté au temps réel, mais proposant un réalisme impressionant.
 
  Mais avant d’atteindre un tel niveau de qualité graphique, commençons par le commmencement : RTv1, votre premier ray tracer en C, à la norme, humble, mais fonctionnel.
  
  Et puis ca fait toujours des jolies images à montrer à votre chéri(e) pour justifier vos longues heures passées á l’école plutôt que dans ses bras :).

## How to

```
make
```

```
./rtv1 <scene_number>
```

## Fonctionnalités

 <table>
   <tr>
       <td>LEFT CLICK</td>
       <td>Sélectionner objet</td>
   </tr>
   <tr>
       <td>RIGHT CLICK</td>
       <td>Désélectionner objet</td>
   </tr>
     <tr>
       <td>UP</td>
       <td>Déplacer caméra / objet vers le haut</td>
   </tr>
     <tr>
       <td>LEFT</td>
       <td>Déplacer caméra / objet vers la gauche</td>
   </tr>
     <tr>
       <td>DOWN</td>
       <td>Déplacer caméra / objet vers le bas</td>
   </tr>
     <tr>
       <td>RIGHT</td>
       <td>Déplacer caméra / objet vers la droite</td>
   </tr>
       <tr>
       <td>A / D</td>
       <td>Pivoter caméra / objet sur l'axe X</td>
   </tr>
       <tr>
       <td>W / S</td>
       <td>Pivoter caméra / objet sur l'axe Y</td>
   </tr>
       <tr>
       <td>SCROLL UP / SCROLL DOWN</td>
       <td>Pivoter caméra / objet sur l'axe Z</td>
   </tr>
     </tr>
       <tr>
       <td>+ / -</td>
       <td>Faire varier l'anti-aliasing</td>
   </tr>
        </tr>
       <tr>
       <td>ESC</td>
       <td>Quitter le programme</td>
   </tr>
</table>

## Exemples

### Scene 6
![img](https://i.imgur.com/8LLAixK.png)

### Scene 7
![img](https://i.imgur.com/09kTcpf.png)

### Scene 8
![img](https://i.imgur.com/n5GfsoL.png)

### Last but not least
![](https://media.giphy.com/media/1BeGacr7uSnIqU5YaO/giphy.gif)
