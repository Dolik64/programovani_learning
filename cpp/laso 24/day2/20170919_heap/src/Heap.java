
/**
 * This class template should be used to implement heap.
 *
 * @author Petr Ryšavý <petr.rysavy@fel.cvut.cz>
 */
final class Heap {

    /** Here we will store values that user will add to the heap. */
    public final int[] heap;
    /** The number of elements in the heap. */
    int length;

    /**
     * Constructs a new heap that will be capable of storing up to {@code n}
     * elements.
     * @param n The maximum number of elements.
     */
    public Heap(int n) {
        this.heap = new int[n + 1];
        length = 0;
    }

    /**
     * Adds a new element to the heap.
     * @param node New walue to add.
     */
    public void add(int node) {
        throw new UnsupportedOperationException("Implement yourself.");
    }

    /**
     * Tests whether this heap is empty.
     * @return {@code true} if there are no elements in the heap.
     */
    public boolean isEmpty() {
        throw new UnsupportedOperationException("Implement yourself.");
    }

    /**
     * Obtains the minimum from the heap.
     * @return The minimum.
     */
    public int extractMin() {
        throw new UnsupportedOperationException("Implement yourself.");
    }

    /**
     * Finds node {@code node} and replaces it with the new value. This method
     * can be used for decreasing key.
     * @param node The original value.
     * @param newValue Its replacement.
     */
    public void replace(int node, int newValue) {
        throw new UnsupportedOperationException("Implement yourself.");
    }

    // you will probably need those private methods
    // however you do not need to strictly follow them, you can design the code
    // yourself
    /**
     * Swaps two values at two particular positions.
     * @param a The first index to swap.
     * @param b The second index.
     */
    private void swap(int a, int b) {
        throw new UnsupportedOperationException("Implement yourself.");
    }

    /**
     * Bubble up node from a position {@code pos}.
     * @param pos The position where we should move the node upwards in order to
     * fix the heap property.
     */
    private void bubbleUp(int pos) {
        throw new UnsupportedOperationException("Implement yourself.");
    }

    /**
     * Bubble up node from a position {@code pos}.
     * @param pos The position where we should move the node downwards in order
     * to fix the heap property.
     */
    private void bubbleDown(int pos) {
        throw new UnsupportedOperationException("Implement yourself.");
    }
}
