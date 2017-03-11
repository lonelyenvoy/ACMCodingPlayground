/**
 * Created by LonelyEnvoy on 2017-3-11.
 * Ignatius and the Princess I
 * Keywords: 迷宫，栈，优先级队列，广度优先搜索
 */

import java.io.*;
import java.util.*;

class Coordinate {
    final int x;
    final int y;

    Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }

    Coordinate createUp() {
        return new Coordinate(x - 1, y);
    }

    Coordinate createDown() {
        return new Coordinate(x + 1, y);
    }

    Coordinate createLeft() {
        return new Coordinate(x, y - 1);
    }

    Coordinate createRight() {
        return new Coordinate(x, y + 1);
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Coordinate)) {
            return false;
        }
        Coordinate c = (Coordinate)o;
        return this.x == c.x && this.y == c.y;
    }

    @Override
    public int hashCode() {
        return x + y;
    }
}

class TraceUnit {
    final Coordinate c;
    final int elapsedTime;

    TraceUnit(Coordinate c, int elapsedTime) {
        this.c = c;
        this.elapsedTime = elapsedTime;
    }

    // only compares coordinate
    @Override
    public boolean equals(Object o) {
        if (!(o instanceof TraceUnit)) {
            return false;
        }
        TraceUnit unit = (TraceUnit)o;
        return this.c == unit.c;
    }
}

public class Main {

    private static int[][] maze; // 0 -- walkable, 1~9 -- monster, 10 -- trap or wall
    private static int[][] direction; // 8 -- up, 2 -- down, 6 -- right, 4 -- left
    private static int n;
    private static int m;

    private static Set<Coordinate> walked = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = reader.readLine()) != null) {
            if (line.length() == 0) { continue; } // ignore empty line

            String[] inputs = line.split(" ");
            n = Integer.parseInt(inputs[0]);
            m = Integer.parseInt(inputs[1]);

            // init walked set
            walked.clear();

            // init maze
            maze = new int[n + 2][m + 2];
            for (int i = 0; i <= n + 1; i++) { // top wall
                maze[i][0] = 10;
            }
            for (int i = 0; i <= n + 1; i++) { // bottom wall
                maze[i][m + 1] = 10;
            }
            for (int i = 0; i <= m + 1; i++) { // left wall
                maze[0][i] = 10;
            }
            for (int i = 0; i <= m + 1; i++) { // right wall
                maze[n + 1][i] = 10;
            }

            // init direction
            direction = new int[n + 2][m + 2];

            // construct maze
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    char c = (char)reader.read();
                    if (c == '\n' || c == '\r') { j--; }
                    else if (c == '.') { } // walkable, do nothing
                    else if (c == 'X') { // trap
                        maze[i][j] = 10;
                    } else { // monster, c >= '1' && c <= '9'
                        maze[i][j] = c - '0';
                    }
                }
            }

            // find a solution
            int elapsedTime = bfs(new Coordinate(1, 1));
            if (elapsedTime == 0) {
                System.out.println("God please help our poor hero.");
                System.out.println("FINISH");
                continue;
            }

            // output result
            System.out.println("It takes " + elapsedTime + " seconds to reach the target position, let me show you the way.");
            printTrace();
        }
    }

    private static int bfs(final Coordinate c) {
        Queue<TraceUnit> visitQueue = new PriorityQueue<>(20, new Comparator<TraceUnit>() {
            @Override
            public int compare(TraceUnit o1, TraceUnit o2) {
                return o1.elapsedTime - o2.elapsedTime;
            }
        });
        TraceUnit unit = new TraceUnit(new Coordinate(1, 1), 0);
        visitQueue.add(unit);
        walked.add(new Coordinate(1, 1));

        while (!visitQueue.isEmpty()) {
            unit = visitQueue.poll();
            if (unit.c.x == n && unit.c.y == m) { // found a solution
                return unit.elapsedTime;
            }

            Coordinate right = unit.c.createRight();
            Coordinate down = unit.c.createDown();
            Coordinate left = unit.c.createLeft();
            Coordinate up = unit.c.createUp();
            int timeRight = maze[right.x][right.y];
            int timeDown = maze[down.x][down.y];
            int timeLeft = maze[left.x][left.y];
            int timeUp = maze[up.x][up.y];

            if (timeRight != 10 && !walked.contains(right)) {
                TraceUnit rightUnit = new TraceUnit(right, unit.elapsedTime + timeRight + 1);
                visitQueue.add(rightUnit);
                direction[rightUnit.c.x][rightUnit.c.y] = 4;
                walked.add(right);
            }
            if (timeDown != 10 && !walked.contains(down)) {
                TraceUnit downUnit = new TraceUnit(down, unit.elapsedTime + timeDown + 1);
                visitQueue.add(downUnit);
                direction[downUnit.c.x][downUnit.c.y] = 8;
                walked.add(down);
            }
            if (timeLeft != 10 && !walked.contains(left)) {
                TraceUnit leftUnit = new TraceUnit(left, unit.elapsedTime + timeLeft + 1);
                visitQueue.add(leftUnit);
                direction[leftUnit.c.x][leftUnit.c.y] = 6;
                walked.add(left);
            }
            if (timeUp != 10 && !walked.contains(up)) {
                TraceUnit upUnit = new TraceUnit(up, unit.elapsedTime + timeUp + 1);
                visitQueue.add(upUnit);
                direction[upUnit.c.x][upUnit.c.y] = 2;
                walked.add(up);
            }

        }
        return 0;
    }

    private static void printTrace() {
        Stack<Coordinate> traceStack = new Stack<>();
        traceStack.push(new Coordinate(n, m));

        // backtrack until (1, 1)
        Coordinate curr = new Coordinate(n, m);
        while (!curr.equals(new Coordinate(1, 1))) {
            switch (direction[curr.x][curr.y]) {
                case 8:
                    traceStack.push(curr = curr.createUp());
                    break;
                case 6:
                    traceStack.push(curr = curr.createRight());
                    break;
                case 4:
                    traceStack.push(curr = curr.createLeft());
                    break;
                case 2:
                    traceStack.push(curr = curr.createDown());
                    break;
            }
        }

        // print
        Coordinate next = new Coordinate(0, 0);
        int time = 0;
        while (traceStack.size() > 1) {
            curr = traceStack.pop();
            next = traceStack.peek();

            int currTime = maze[curr.x][curr.y];
            // check if there is a monster
            if (currTime == 0) {
                System.out.println((++time) + "s:(" + (curr.x - 1) + "," + (curr.y - 1) + ")->("
                        + (next.x - 1) + "," + (next.y - 1) + ")");
            } else {
                while (--currTime >= 0) {
                    System.out.println((++time) + "s:FIGHT AT (" + (curr.x - 1) + "," + (curr.y - 1) + ")");
                }
                System.out.println((++time) + "s:(" + (curr.x - 1) + "," + (curr.y - 1) + ")->("
                        + (next.x - 1) + "," + (next.y - 1) + ")");
            }
        }
        // parse fight at the exit (if exist)
        int finalTime = maze[n][m];
        if (finalTime > 0) {
            while (--finalTime >= 0) {
                System.out.println((++time) + "s:FIGHT AT (" + (next.x - 1) + "," + (next.y - 1) + ")");
            }
        }

        System.out.println("FINISH");
    }
}