pub fn add(left: usize, right: usize) -> usize {
    left + right
}

#[no_mangle]
pub extern "C" fn process_audio(buffer: *mut f32, num_channels: usize, num_samples: usize) {
    unsafe {
        // Ensure we have a valid pointer and sensible sizes.
        if buffer.is_null() || num_channels == 0 || num_samples == 0
        {
            return;
        }

        // Convert the raw pointer to a mutable slice
        let total_samples = num_channels * num_samples;
        let buffers = std::slice::from_raw_parts_mut(buffer, total_samples);

        // Example: Process each sample (flattened iteration)
        for sample in buffers.iter_mut()
        {
            let input = *sample * 10.0;
            *sample = 2.0 / 3.14 * input.atan();
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}
