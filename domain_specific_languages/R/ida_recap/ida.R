// Sample from known distributions
// Plot them
// Find quantiles, quartiles and probabilities for intervals
// Plot probability intervals
//

x <- rnorm(10000,10,0.001)
mean(x)
y <- rnorm(10000,10,0.001)
mean(y)
t.test(x,y,var.equal=TRUE, alternative="two.sided")

x <- rnorm(10000,150,0.1)
mean(x)
y <- rnorm(10000,10,20.1)
mean(y)
t.test(x,y,var.equal=TRUE, alternative="two.sided")

plot(seq(-5,5,by=0.1), dnorm(seq(-5,5,by=0.1),0,1),col="red",type="line")
pnorm(0.1,mean=0,sd=1)
plot(seq(-5,5,by=0.1), pnorm(seq(-5,5,by=0.1),0,1),col="red",type="line")

model = lm(y~x)
summary(model)
y=3*x
model = lm(y~x)
summary(model)


//Fisher test from the example
TeaTasting <-
    matrix(c(3, 1, 1, 3),
           nrow = 2,
           dimnames = list(Guess = c("Milk", "Tea"),
                           Truth = c("Milk", "Tea")))
TeaTasting
fisher.test(TeaTasting, alternative = "greater")
## => p = 0.2429, association could not be established
fisher.test(TeaTasting, alternative = "two.sided")

TeaTasting <-
    matrix(c(7, 0, 1, 5),
           nrow = 2,
           dimnames = list(Guess = c("regu", "rare"),
                           Truth = c("pass", "fail")))
TeaTasting
fisher.test(TeaTasting, alternative = "greater")
## => p = 0.004662, H0 hypothesis (assumption of independence) is rejected

shoesize <- c(38,38,39,39,40,40,41,41,42,42)
bodysize <- c(153,161,167,169,173,176,182,181,188,189)
bspl <- data.frame(shoesize, bodysize)
bspl
fm <- lm(bodysize ~ shoesize, data=bspl)
fm
summary(fm)

fm$residuals

plot(shoesize,bodysize)
abline(coef(fm),col="red")
points(shoesize,fitted(fm),col="red")
coef(fm)
fitted(fm)

fm_s=lm(bodysize ~ I(shoesize-40), data=bspl)
fm_s
shoesize-40
I(shoesize-40)
plot(I(shoesize-40),bodysize)
abline(coef(fm_s),col="red")
points(I(shoesize-40),fitted(fm_s),col="red")

fm_sc=lm(bodysize ~ I((shoesize-40)/(42-40)), data=bspl)
fm_sc
plot(I((shoesize-40)/(42-40)),bodysize)
abline(coef(fm_sc),col="red")
points(I((shoesize-40)/(42-40)),fitted(fm_sc),col="red")

fmsq <- lm(bodysize ~ shoesize + I(shoesize^2), data=bspl)
fmsq
summary(fmsq)
fitted(fmsq)
plot(shoesize,fitted(fmsq))
points(shoesize, bodysize)
points(shoesize,fitted(fmsq), col="red")
lines(formula=fitted (fmsq)~shoesize, col="red")
abline(coef(fm),col="green")

fm_s_sq<-lm(bodysize ~ I(shoesize-40) + I((shoesize-40)^2), data=bspl)
fm_s_sq
fm_sc_sq<-lm(bodysize ~ I((shoesize-40)/(42-40)) + I((shoesize-40)^2/4), data=bspl)
fm_sc_sq
summary(fm_sc_sq)

step(fmsq)

qqnorm(resid(fmsq))

boxplot(rnorm(100,10,2))
