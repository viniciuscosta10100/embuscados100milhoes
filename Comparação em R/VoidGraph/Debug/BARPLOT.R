graficobarra1<-read.table("BARPLOT.txt",header=TRUE,sep="")
graficobarra1<-as.matrix(graficobarra1)
barplot(graficobarra1,beside=TRUE,legend.text=rownames(graficobarra1),main="Bubblesort x Heapsort - Comparações",ylab="N.de comparações",xlab="Algoritmos de ordenação")
