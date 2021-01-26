# Journey-to-Dragon-s-Hollow
Two heroes make their way across Dragon’s Hollow (moving from the left-hand side to the right-hand side), fights guards on the way, reach to the rightmost of the map without dying.

Initially,
(a) Two Heroes Timmy (represented by his avatar ’T’) and Harold (with avatar ’H’) are situated at the leftmost edge of the Hollow, at different randomly generated vertical positions.
(b) The Dragon (represented by its avatar ’D’) is situated at the right-most edge of the Hollow, at the midpoint on the vertical axis.

Timmy and Harold each begin with 15 health points. Timmy has a strength of 3 points and an armour of 3 points, and Harold has a strength of 5 points and an armour of 1 point.

With a probability of 60%, the program generates a new ﬁghter:
(a) A new ﬁghter has equal probability of being a dorc, a borc, or a porc. Dorcs are represented by the avatar ’d’, borcs by ’b’, and porcs by ’p’. Every time, there is also a 1/5 chance to create an angel somewhere in the middle of the Hollow.
(b) Fighters are initially situated on the right-most edge of Dragon’s Hollow, at a randomly generated vertical position in front of the cave.
(c) Fighters begin with 5 health points, and a randomly generated strength in the following ranges: dorcs begin with a strength between 6 and 8 points (inclusively), borcs with a strength between 8 and 11 points, and porcs between 4 and 5 points.

The angel has an effective recovering radius of 1.
If a hero is in an angels' range, the hero will get 2 points of health, however, the health may not exceed heroes' max health.
If two heroes are both in angels' range, each hero will get 1 point of health, but if one hero is health and the other is not, the other hero will get full 2 point	health.

If a hero collides with the Dragon, the hero instantly dies.
If a hero and a ﬁghter collide, both quest players take a hit, as follows:
(i) If Timmy or Harold takes a hit, that hero’s health is decreased by the damage inﬂicted by the ﬁghter. The damage is equal to the ﬁghter’s strength, minus the hero’s armour. When a hero’s health reaches zero, he dies. If two heroes meet a fighter together, each of them will take half of the damage, Timmy will take the rounded up damage if the damage is odd. If an angel touches a fighter(same position), the angel dies immediately. If a hero (both heroes) is fighting a fighter and in an angel's range at the same time, the hero will get the health first, and then battle with the fighter. If the angle is at the same position with a fighter and a hero (two heroes), the hero will protect the Angel, the angel will survive. 

(ii) If a ﬁghter takes a hit, that ﬁghter’s health is decreased by the damage inﬂicted by the hero, which is equal to the hero’s strength. When a ﬁghter’s health reaches zero, it dies.

