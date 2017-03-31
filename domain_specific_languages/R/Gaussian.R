x <- y <- seq(-10, 10, len = 200)
X <- expand.grid(x = x, y = y)
X <- transform(X, z = dnorm(x, -2.5, sd=2.3)*dnorm(y+5, sd=2.3) 
               + dnorm(x-3, 2.5, sd=2.3)*dnorm(y-1, sd=2.3)
               + dnorm(x+7, 2.5, sd=2.3)*dnorm(y-3, sd=2.3))
z <- matrix(X$z, nrow = 200)

persp(x, y, z, 
      r = 1, d = 5, scale=TRUE,
      col = "darkgrey", border = NA, expand = 0.25,
      theta = 50, phi = 35, ticktype = "detailed", 
      ltheta = -135, lphi = -20, shade = 0.25)

