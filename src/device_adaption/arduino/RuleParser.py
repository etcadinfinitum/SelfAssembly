class RuleParser:
    def __init__(self, data):
        '''
        Construct RuleParser object.
        '''
        self.data = data
        import pdb; pdb.set_trace()

    def __len__(self):
        return len(self.rules)

    def __iter__(self):
        '''
        Iterates over rules parsed by the object.
        '''
        return self

    def __next__(self):
        '''
        Return next rule in iteration.
        '''
        for item in self.rules:
            yield item

    def build_ruleset(self):
        if not data:
            raise Exception('Ruleset has not been imported.')
        for line in data:
            pass

    def enumerate_labels(self):
        # TODO: implement
        pass

