data=load("px.txt");
x=reshape(data(:,1),18,18);
%y=reshape(data(:,2),18,18);
z=reshape(data(:,3),18,18);
contourf(x,z);
%surf(x,y,z);
xlabel("x");
%ylabel("y");
zlabel("z");
colorbar("southoutside");
title("Pochodna X");
