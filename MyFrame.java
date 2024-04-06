import javax.swing.*;
import java.awt.*;
import java.awt.geom.GeneralPath;

public class MyFrame extends JFrame {
    public MyFrame() {
        setSize(600, 600);
        setLocation(300, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
        getContentPane().setBackground(Color.black);
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D gg = (Graphics2D) g;
        gg.setStroke(new BasicStroke(3));
        gg.setColor(Color.yellow);
        gg.setRenderingHint(RenderingHints.KEY_ANTIALIASING,RenderingHints.VALUE_ANTIALIAS_ON);

        drawganeralpath(gg);


    }
    private void drawganeralpath(Graphics2D painter) {
        GeneralPath p = new GeneralPath();

        p.moveTo(100,200);
        p.lineTo(140,200);
        p.quadTo(160,240,180,200);
        p.lineTo(220,200);
        p.quadTo(240,240,260,200);
        p.lineTo(300,200);
        p.lineTo(300,160);
        p.curveTo(280,120,270,120,260,120);
        p.lineTo(180,120);
        p.lineTo(140,160);
        p.lineTo(100,160);
        p.lineTo(100,200);

        painter.draw(p);
    }

}