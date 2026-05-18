import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class Main {

    public static void main(String[] args) {
        // Příklad použití Collection
        Collection<String> collection = new ArrayList<>();
        collection.add("Item 1");
        collection.add("Item 2");
        collection.add("Item 3");
        System.out.println("Collection: " + collection);
        System.out.println("Contains 'Item 2': " + collection.contains("Item 2"));
        collection.remove("Item 2");
        System.out.println("Collection after removal: " + collection);

        // Příklad použití List
        List<String> list = new ArrayList<>();
        list.add("Element 1");
        list.add("Element 2");
        list.add("Element 3");
        System.out.println("List: " + list);
        System.out.println("Element at index 1: " + list.get(1));
        list.remove(1);
        System.out.println("List after removal: " + list);

        // Příklad použití Set
        Set<String> set = new HashSet<>();
        set.add("Item A");
        set.add("Item B");
        set.add("Item C");
        set.add("Item A"); // Duplicitní prvek nebude přidán
        System.out.println("Set: " + set);
        set.remove("Item B");
        System.out.println("Set after removal: " + set);

        // Příklad použití Queue
        Queue<String> queue = new LinkedList<>();
        queue.add("First");
        queue.add("Second");
        queue.add("Third");
        System.out.println("Queue: " + queue);
        System.out.println("Head of queue: " + queue.peek());
        queue.remove();
        System.out.println("Queue after removal: " + queue);

        // Příklad použití Map
        Map<String, Integer> map = new HashMap<>();
        map.put("Key1", 1);
        map.put("Key2", 2);
        map.put("Key3", 3);
        System.out.println("Map: " + map);
        System.out.println("Value for 'Key2': " + map.get("Key2"));
        map.remove("Key2");
        System.out.println("Map after removal: " + map);
    }
}
